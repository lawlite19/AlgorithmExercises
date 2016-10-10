/*
问题：求数组中逆序对个数，即如果前面的数大于后面的数，则构成一个逆序对
		Poj problem1804 Accept(http://poj.org/problem?id=1804)
	
思路：采用归并排序的思想，
	（1）因为合并过程是将两部分合并成一部分，在合并的过程中，如果前面部分某个数大于后面的部分的
		数，则构成逆序对 
	（2）合并的时候两部分是有序的，所以当前位置i如果大于后面j位置的数，则i到mid之间的数都是大于后面j位置的数的
		count+=mid-i+1; 
*/
#include <stdio.h>

long long count; 
//合并 
void merge(int *a,int left,int mid,int right)
{
	int b[100000];
	int i=left,j=mid+1,k=left;//i指向左边开始左边，j指向右边开始坐标，k记录存储用户合并的b数组位置 
	while(i<=mid&&j<=right){//i、j同时开始扫描 
		if(a[i]>a[j]){//若是左边部分大于右边部分，j向后移（即将两部分小的元素放到b数组中） 
			b[k++]=a[j++];
			count+= mid - i + 1;//构成逆序对，count+=mid-i+1,因为都是有序的，i位置处>a[j]，则i--mid都是>a[j] 
		}
		else//否则i向后移 
			b[k++]=a[i++];
	}
	while(i<=mid)//有可能一遍先遍历完，然后将另一遍剩余的继续放在b数组 
		b[k++]=a[i++];
	while(j<=right)//同上 
		b[k++]=a[j++];
	for(i=left;i<=right;i++)//这里将合并的b数组复制到a数组中
		a[i]=b[i];
}
//归并排序-递归 
void mergeSort(int *a,int left,int right)
{
	int mid;
	if(left<right){
		mid=(left+right)/2;//计算中点 
		mergeSort(a,left,mid);//递归划分左半边 
		mergeSort(a,mid+1,right);//递归划分右半边 
		merge(a,left,mid,right);//合并两部分 
	} 
}

int main()
{
    int n,time,tt=1,a[100000];  
    scanf("%d",&time);  
    while(time--)
    {  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        count = 0;  
        mergeSort(a,0,n-1);  
        printf("Scenario #%d:\n%d\n\n",tt++,count);  
    }  
    return 0;  
} 
