/*
问题：求一个数组的最大子数组和 

1、sum为当前一个子数组的和，max存储最大值
2、遍历数组，累加到sum上，与max相比，若大于max，更新max值。若是sum<0，则重置sum=0 

为什么这种计算是正确的，假设一个子数组是最大的，则其任意前缀必不为负数，因为要是负数还不如不要这个前缀，这样数更大 
*/
#include <iostream>
using namespace std;	

#define INT_MIN (-2147483647 - 1) 

int maxSubSum(int *a,int len)
{
	int sum=0;//存储当前计算的数组和 
	int max=INT_MIN;//max开始取很小的值 
	for(int i=0;i<len;++i){//遍历数组 
		sum+=a[i];//求和 
		if(sum>max)//与max比较 
			max=sum;
		if(sum<0)//若sum为负，重置 
			sum=0;
	}
	
	return max;
} 

int main()
{
	//输入
	int *a,data,n=0;
	cout<<"请输入数组元素（以-1结尾）："<<endl;
	while(cin>>data && data!=-1){
		a[n++]=data;
	} 
	
	//输出结果
	cout<<"结果为："<<maxSubSum(a,n)<<endl; 
	return 0;
} 
