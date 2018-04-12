/*
数组跳跃：
问题： 
-  一个非负数组，当前数组表示能够挑的最大步数，求从开始到末尾的最小跳跃次数
- eg: A = [2,3,1,1,4] , 需要2步即可 
方法：
- dp：H[i]表示index从0到i的最少跳数 
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1000

int minJump(vector<int> data)
{
	int len = data.size();
	vector<int> dp(len, 0);  //初始化len个0值的vector
	for(int i=0;i<len-1;i++){
		for(int j=1;j<=data[i];j++){
			if(dp[i+j]>dp[i]+1 || dp[i+j]==0)
				dp[i+j] = dp[i]+1;
		}
	}	
	return dp[len-1];
}

int main()
{
	int n,d;
	cin>>n;
	vector<int> data;
	while(n--){
		cin>>d;
		data.push_back(d);
	}
	cout<<minJump(data)<<endl;
	return 0;
} 
