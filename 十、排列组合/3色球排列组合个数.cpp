/**
problem： n个红球，m个白球，k个绿球，相邻颜色不同的排列组合个数 
solution1: 最后一个球需要n 
           最后一个球需要m
           最后一个球需要k
solution2: 直接递归时间复杂度是指数级的，因为一些结果重复计算， 可以使用数组暂存结果           
		    
**/ 

#include <iostream>
#include <memory.h> 
using namespace std;
#define MAX 100
long long dp[MAX][MAX][MAX][3];

////solution1 
//long long countWays(long long n, long long m, long long k, long long last){   // last代表需要的是哪个球，0代表n, 1代表m, 2代表k 
//	if(n<0 || m<0 || k<0)   
//		return 0;
//	if(n==1 && m==0 && k==0 && last==0)         // 需要n, 且n==1，其余为0, 只有一种排列 
//		return 1;
//	if(n==0 && m==1 && k==0 && last==1)         // 同理 
//		return 1;
//	if(n==0 && m==0 && k==1 && last==2)
//		return 1;
//	
//	if(last==0)                                //需要n，则剩余为n-1, m, k, 需要的是1， 2结果之和 
//		return countWays(n-1, m, k, 1) + countWays(n-1, m, k, 2);
//	if(last==1) 
//        return countWays(n, m-1, k, 0) + countWays(n, m-1, k, 2); 
//    if(last==2) 
//        return countWays(n, m, k-1, 0) + countWays(n, m, k-1, 1); 	
//}

//solution2
long long countWays(long long n, long long m, long long k, long long last){   // last代表需要的是哪个球，0代表n, 1代表m, 2代表k 
	if(n<0 || m<0 || k<0)   
		return 0;
	if(n==1 && m==0 && k==0 && last==0)         // 需要n, 且n==1，其余为0, 只有一种排列 
		return 1L;
	if(n==0 && m==1 && k==0 && last==1)         // 同理 
		return 1L;
	if(n==0 && m==0 && k==1 && last==2)
		return 1L;
	
	if(dp[n][m][k][last] != -1)
		return 	dp[n][m][k][last];
	
	if(last==0)                                //需要n，则剩余为n-1, m, k, 需要的是1， 2结果之和 
		dp[n][m][k][last] = countWays(n-1, m, k, 1) + countWays(n-1, m, k, 2);
	if(last==1) 
        dp[n][m][k][last] = countWays(n, m-1, k, 0) + countWays(n, m-1, k, 2); 
    if(last==2) 
        dp[n][m][k][last] = countWays(n, m, k-1, 0) + countWays(n, m, k-1, 1); 	
	return dp[n][m][k][last]; 
}



long long countAll(long long n, long long m, long long k){
	memset(dp, -1L, sizeof(dp));
	return countWays(n, m, k, 0) +
	       countWays(n, m, k, 1) +
	       countWays(n, m, k, 2);
}

int main(){
	long long n, m, k;
	cin>>n>>m>>k;
	cout<< countAll(n, m, k)<<endl;
	
	return 0; 
} 
