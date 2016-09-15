/*
问题：求一个数组的最长递增子序列

O（n^2）的解法：
1、求dp数组，dp[i]代表以a[i]结尾的条件下最长递增子序列的长度（dp[i]可以根据dp[i-1]求出） 
2、当球dp[i]时，需要遍历dp[0..i-1]（j），如果当前a[i]大于a[j],dp[i]=max{dp[j]+1} 

求出dp后遍历即可得到最大长度是多少，下面求最大长度对应的序列
1、从后往前，遍历到最大dp[i]处，往前遍历
2、若是dp[j]=dp[i]-1 且a[j]<a[i]，即为所求
3、...... 
 
*/
#include <stdio.h>
#include <stack>
using namespace std;

//求dp数组 
void getdp(int *a,int *dp,int len)
{
	for(int i=0;i<len;++i){//遍历 
		dp[i]=1;//先设置为1 
		for(int j=0;j<i;++j)//遍历0..i-1 
			if(a[i]>a[j])//如果当前a[i]>a[j],dp[i]取满足这个条件最大dp的值+1 
				dp[i]=dp[i]>(dp[j]+1) ? dp[i] : (dp[j]+1);//因为j在变动过程中dp[i]也是变化的，所以是dp[i]=max(dp[i],dp[j]+1) 
	}
}

//求最长序列元素 
void getLongestList(int *a,int len)
{
	int dp[len];
	getdp(a,dp,len);//得到dp数组 
	
	int maxLen=0;
	int index=0;
	for(int i=0;i<len;++i)//遍历dp，求得最长值 
		if(dp[i]>maxLen){
			maxLen=dp[i];
			index=i;
		}
	printf("最长递增子序列长度为:%d\n",maxLen);
	
	stack<int> list;//声明栈，方便输出序列（因为是从后向前求具体的序列） 
	list.push(a[index]);//先将最后的入栈 
	for(int i=index;i>=0;--i)//从后向前遍历 
		if(a[i]<a[index] && dp[i]==dp[index]-1){//如果前面的比当前小，且dp数组满足小1关系，入栈 
			list.push(a[i]);
			index=i;//同时将index修改为遍历到的位置 
		}
	printf("最长递增子序列为：");
	while(!list.empty()){//输出 
		printf("%d ",list.top());
		list.pop();
	}			
	printf("\n");
}


int main(int argc,char *argv[])
{
	//输入 
	printf("请输入一序列数字（以-1结尾）：");
	int n=0,a[100],data;
	while(scanf("%d",&data) && data!=-1){
		a[n++]=data;
	} 
	
	getLongestList(a,n);

	return 0;
} 
