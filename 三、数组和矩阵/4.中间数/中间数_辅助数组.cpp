/*
问题：这里中间数的定义 1、前面有比当前数小的
					   2、后面有比当前数大的
思路 1、遍历过程中依次再遍历当前数前面的和后面的数（O(n^2)）
	 2、要想在遍历过程中不用再遍历当前数的前后，而是直接拿到前面数的最小值，后面数的最大值比较即可 （O(N)） 
	 	（1）正向遍历，将当前数的最小值保存到数组中 
		（2）反向遍历，将当前数的最大值从后往前保存到另外一个数组中 
	    （3）然后再遍历一遍判断即可
		优化：最小值的数组实际不需要，因为在判断的过程中也是正向遍历，所以直接使用一个
			变量存储即可。 
*/
#include <stdio.h>
#include <iostream>
using namespace std;
void getMedians(int *a,int len)
{
	int m[len];//存储最大值数据 
	m[len-1]=a[len-1];
	for(int i=len-2;i>1;--i)//从后往前遍历，得到最大值数组（i坐标到2即可，因为从1处开始判断） 
		if(a[i]>m[i+1])
			m[i]=a[i];
		else
			m[i]=m[i+1];
			
	int curMin=a[0];//记录当前数前的最小值 
	for(int i=1;i<len-1;++i){//遍历到倒数第二个数 
		if(a[i]<m[i+1] && a[i]>curMin)//判断 
			printf("%d ",a[i]);
		if(a[i]<curMin)//若当前数小于前面的最小值，更新最小值 
			curMin=a[i];
	}
}

int main()
{
	int a[]={8,2,4,5,6,3};
	int len=sizeof(a)/sizeof(int); 
	
	printf("中间的数有：");
	getMedians(a,len); 
	return 0;
} 
