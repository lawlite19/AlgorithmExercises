/*
问题：求一个非负数数组中子数组和为K的最大长度

思路：1、定义两个指针left和right，初始都指向数组开始（计算left和right之间的和） 
	  2、遍历，终止条件是right指针移动到最后
	  3、sum求当前和，如果sum==k,则right-left+1即为子数组的长度，记录最大值，同时sum要减去左边的值，左指针left前移
	  				  如果sum <k, 右指针right前移，同时需要判断一下是否越界（若越界，直接break），然后sum+a[right]
					  如果sum >k, sum减去左指针指向的值，同时前移 
*/
#include <stdio.h>

int longestSubArrayK(int *a,int k,int len)
{
	int left=0;//左指针 
	int right=0;//右指针 
	int sum=a[0];//存储累加和
	int maxLen=0;//记录最大长度 
	while(right<len){//遍历，右指针right移到末尾结束 
		if(sum==k){//记录最大值，sum减去left指向的值，然后left前移 
			maxLen=maxLen>(right-left+1) ? maxLen : (right-left+1);
			sum-=a[left];
			++left;
		}
		else if(sum<k){//右指针前移，同时判断一下前移后是否越界，然后计算累加 
			++right;
			if(right>=len)
				break;
			sum+=a[right]; 
		}
		else{//sum减去left指向的值，然后left前移
			sum-=a[left];
			++left;
		}
	}
	
	return maxLen;
}

int main()
{
	int a[]={2,1,4,5,1,1,1,3,4,2,3,4,1};
	int len=sizeof(a)/sizeof(int);
	int k=3; 
	printf("和为 %d 的最长子数组长度为：%d\n",k,longestSubArrayK(a,k,len)); 
	
	return 0;
}
