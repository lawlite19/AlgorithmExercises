/*
问题：一个序列中只有一个数出现奇数次，其余的数都出现偶数次，求出这个数

亦或运算：1^1=0  0^0=0  1^0=1  0^1=1
所以将所有数亦或的话，相同的数对应位相同，亦或之后为0，再与不同的数亦或，最后就是结果 
*/ 
#include <stdio.h>
#include <vector>
using namespace std;

int oddTimeNumber(int *a,int len)
{
	int i=0;//i用于遍历 
	int res=0;//res记录结果，初值为0 
	while(i<len){
		res ^= a[i];//亦或运算 
		i++;
	} 
	return res;
}


int main()
{
	int a[]={2,3,2,4,5,4,5,6,7,7,6};
	int len=sizeof(a)/sizeof(int);//求长度 
	//结果
	printf("出现奇数次的结果为：%d\n",oddTimeNumber(a,len)) ;
	return 0;
}
