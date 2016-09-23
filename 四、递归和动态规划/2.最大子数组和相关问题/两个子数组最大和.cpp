/*
问题：求一个序列中两个不相容的子序列的最大和（不相容即为不能相交）

	  POJ 2479题（Accepted）：Maximum sum （http://poj.org/problem?id=2479） 

思路：1、遍历序列，以当前数作为划分点，分别求前后的最大子序列和，然后保留最大值
	  2、求最大子序列问题可以参考上一题中的dp方法
	  3、关于如何最终在O(N)的时间得到结果，就需要求前后最大子序列的时间复杂度为O(1)，
	  	 所以先遍历一遍序列，定义两个个数组分别从前往后、从后往前存取当前数的最大子序列，
		 这样就直接取数得到前后的最大子序列值就可以了 
	优化：可以省略存取从前往后的最大子序列的数组，因为我们可以在最终遍历序列的过程中，使用一个变量
		存储当前数前的最大子序列值即可。 
 
*/
#include <stdio.h>

#define INT_MIN (-2147483647 - 1) //宏定义，定义int的最小值（包含limits.h头文件也可以） 

int getMaxSum(int *a,int len)
{
	int dp[len];//用于存储从后往前的最大子序列值 
	int sum=0;//记录当前从后往前遍历的累加和 
	int max=INT_MIN;//记录最大值，初始值最小化 
	for(int i=len-1;i>=0;--i){//从后往前遍历 
		if(sum<0)//若当前累加和<0，则重置为0 
			sum=0;
		sum+=a[i];//累加 
		max=max>sum ? max : sum;//判断当前最大值和累加和的关系 
		dp[i]=max;//将大的值放入dp数组 
	}
	
	int curSum=0;//记录当前从前往后遍历的累加和 
	int max2=INT_MIN;//记录当前最大值 
	int res=INT_MIN;//记录计算的最终结果 
	for(int i=0;i<len-1;++i){//从前往后遍历 
		if(curSum<0)
			curSum=0;
		curSum+=a[i];
		max2=max2>curSum ? max2 : curSum;//求从前往后的最大子序列，与上同理  
		
		res=res>(max2+dp[i+1]) ? res : (max2+dp[i+1]);//res取最大的值	
	}
	return res;
}

int main()
{
	/*
	int a[]={1,-1,2,2,3,-3,4,-4,5,-5};
	int len=sizeof(a)/sizeof(int);
	printf("两个不相容子序列的最大和：%d\n",getMaxSum(a,len));
	*/
	
	/*
	poj上test case的输入是： 
		1、先输入总共多少条测试记录
		2、然后是序列的长度
		3、然后是序列的具体元素	
	*/ 
	int a[50000];
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		printf("%d\n",getMaxSum(a,n));
	}
	
	return 0;
}
