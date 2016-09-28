/*
问题：数组中出现次数大于一半的数
		leetcode169. Majority Element

思路：1、首先选出可能超过一半的数，然后再遍历一遍判断即可
		（若是存在大于一半的数，则相互抵消两个不同的数最后剩余的即为结果） 
	  2、count计数（初始值0），res，存储结果，遍历，若是count为0，则设置res为当前数
	  	同时count++，否则如果当前数不等于res，则抵消，count--，否则count++
      3、然后遍历一遍统计res出现的次数 （因为有可能两个不是结果的数抵消了，则结果不一定正确） 
*/ 
#include <stdio.h>

void majorityNumber(int *a,int len)
{
	if(len<1)
		return;
	
	int count=0;//记录遍历当前数出现次数 
	int res;	//记录可能结果 
	for(int i=0;i<len;++i){//遍历 
		if(count==0){//如果count为0，则设置res为当前数，同时count=1 
			res=a[i];
			count=1;
		}
		else if(res!=a[i])//否则如果不相等，则抵消，count-- 
			--count;
		else
			++count;//相等，count++ 
	}
	//以上因为count进来就会设置为1，后序--后变为0，再次遍历进来又会设置为1,所以count不会小于0 
	
	//下面则为再遍历一遍判断是否大于一半（因为有可能两个不是结果的数抵消了，则结果不一定正确） 
	count=0;
	for(int i=0;i<len;++i)
		if(a[i]==res)
			++count;
	if(count>len/2)
		printf("%d\n",res);
	else
		printf("不存在次数大于一半的数"); 
}

int main()
{
	int a[]={3,4,2,5,1,2,2,3,4,2,2,1,2,2,2,2};
	int len=sizeof(a)/sizeof(int);
	
	majorityNumber(a,len); 
	
	return 0;
} 
