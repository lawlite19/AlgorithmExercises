/*
问题：求和为K的最长子数组长度
		leetcode325. Maximum Size Subarray Sum Equals k 

思路： 
*/
#include <stdio.h>
#include <map>
using namespace std;

int max(int a,int b)
{
	return a > b ? a : b; 
}

int maxLengthK(int *a,int k,int len)
{
	if(len<1)
		return 0;
		
	map<int,int> helpMap;
	helpMap[0]=-1;
	int maxLen=0;
	int sum=0;
	
	for(int i=0;i<len;++i){
		sum+=a[i];
		map<int,int>::iterator iter;
		iter=helpMap.find(sum-k);
		if(iter != helpMap.end())
			maxLen=max((i-helpMap[sum-k]),maxLen);
		else
			helpMap[sum]=i;
	}
	
	return maxLen;
}

int main()
{
	int a[]={1,2,3,3,2,3};
	int k=6;
	int len=sizeof(a)/sizeof(int);
	
	printf("最大长度为：%d\n",maxLengthK(a,k,len)); 
	
	return 0;
}
