/*
问题：查找两个有序数组的中位数，若总个数为奇数，返回中位数，若为偶数，返回(x1+x2)/2 
		eg：nums1 = [1, 2]
			nums2 = [3, 4]
			中位数为(2 + 3)/2 = 2.5 
		Leetcode 4. Median of Two Sorted Arrays（Accepted） 
思路：详见算法说明（技巧性略强） 

时间复杂度：O（log(min(m,n))） 
*/ 
#include <stdio.h>
#include <limits.h>

int min(int a,int b)
{
	return a > b ? b : a;	
}
int max(int a,int b)
{
	return a > b ? a : b;
}

double findMedianSortedArrays(int* a, int n, int* b, int m) 
{
    if(n>m)	//二分较小的数组 
		return  findMedianSortedArrays(b,m,a,n);
	
	int l1;		//a中割点的左边，即左边最大值 
	int l2;		//b中割点的左边，即左边最大值 
	int r1;		//a中割点的右边，即右边最大值 
	int r2;		//b中割点的右边，即右边最大值 
	int c1;		//a中割点的位置 
	int c2; 	//b中割点的位置 
	int low=0;	//a中开始 
	int high=2*n;	//a中增加虚拟#后的结尾 
	
	while(low<=high){	//二分较短的数组开始 
		c1=(low+high)>>1;	//a中割点位置 
		c2=n+m-c1;			//b中割点位置 
		l1=(c1==0) ? INT_MIN : a[(c1-1)>>1];//a中割点的左边 
		r1=(c1==2*n) ? INT_MAX : a[c1>>1];	//a中割点的右边 
		l2=(c2==0) ? INT_MIN : b[(c2-1)>>1];//b中割点的左边 
		r2=(c2==2*m) ? INT_MAX : b[c2>>1];	//b中割点的右边 
		
		if(l1>r2)		//二分left区域
			high=c1-1;
		else if(l2>r1)	//二分right区域 
			low=c1+1;
		else			//找到结果，即l1<r2,且l2<r1 
			break;
	}
	
	return (max(l1,l2)+min(r1,r2))/2.0;//返回左边两个数的最大值和右边两个的最小值的1/2 
}

int main()
{
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(int);
	int b[]={3,4,5,6};
	int m=sizeof(b)/sizeof(int);
	
	printf("中位数为：%f",findMedianSortedArrays(a,n,b,m));
	
	return 0;
} 
