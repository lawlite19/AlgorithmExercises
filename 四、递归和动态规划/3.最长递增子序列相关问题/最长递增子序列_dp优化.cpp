/*
问题：求一个数组的最长递增子序列

O（NlogN）的解法(就是求dp数组的时间复杂度,主要利用二分进行优化)：
1、使用辅助数组end[]，end[i]记录i+1长度的递增序列的最小末尾数，维护一个递增的序列，所以可以二分查找 
2、dp[i]的值即为插入end数组位置对应的长度（因为前面都是小的） 


求出dp后遍历即可得到最大长度是多少，下面求最大长度对应的序列
1、从后往前，遍历到最大dp[i]处，往前遍历
2、若是dp[j]=dp[i]-1 且a[j]<a[i]，即为所求
3、...... 
*/ 
#include <stdio.h>
#include <stack>
using namespace std;

//得到dp数组 
void getdp(int *a,int *dp,int len)
{
	int end[len];//声明end辅助数组 
	end[0]=a[0];//第一位为a[0] 
	dp[0]=1;//dp第一位为1 
	int right=0;//end有效区位置 
	int l=0;//有效区左边 
	int r=0;//有效区右边 
	int m=0;//有效区中间 
	for(int i=0;i<len;++i){
		l=0;//每次l到最左边 
		r=right;//r到最右边 
		while(l<=r){//二分查找end数组,这里是<=，所以没找到l=right+1,有效区会扩一位**** 
			m=(l+r)/2; 
			if(a[i]>end[m])
				l=m+1;
			else
				r=m-1;
		}
		right=right>l ? right:l;//修改有效区位置 
		end[l]=a[i];//要插入的位置 
		dp[i]=l+1;//dp[i]为有效区的长度，即为l+1 
	} 
}

void getLongestList(int *a,int len)
{
	int dp[len];
	getdp(a,dp,len);
	
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
	printf("请输入序列（以-1结尾）："); 
	int n=0,data,a[100];
	while(scanf("%d",&data) && data!=-1){
		a[n++]=data;
	}
	
	getLongestList(a,n);
	
	return 0;
} 
