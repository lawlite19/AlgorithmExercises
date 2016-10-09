#include <iostream>
using namespace std;

int count=0; 
//合并 
void merge(int *a,int *b,int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;//i指向左边开始左边，j指向右边开始坐标，k记录存储用户合并的b数组位置 
	while(i<=mid&&j<=right){//i、j同时开始扫描 
		if(a[i]>=a[j]){//若是左边部分大于右边部分，j向后移（即将两部分小的元素放到b数组中） 
			b[k++]=a[j++];
			count+= mid - i + 1;
		}
		else//否则i向后移 
			b[k++]=a[i++];
	}
	while(i<=mid)//有可能一遍先遍历完，然后将另一遍剩余的继续放在b数组 
		b[k++]=a[i++];
	while(j<=right)//同上 
		b[k++]=a[j++];
	for(i=left;i<=right;i++)//这里将合并的b数组复制到a数组中，其实不复制也可以，b数组存储的就是排好序的 
		a[i]=b[i];
}
//归并排序-递归 
void mergeSort(int *a,int *b,int left,int right)
{
	int mid;
	if(left<right){
		mid=(left+right)/2;//计算中点 
		mergeSort(a,b,left,mid);//递归划分左半边 
		mergeSort(a,b,mid+1,right);//递归划分右半边 
		merge(a,b,left,mid,right);//合并两部分 
	} 
}

int main()
{
	int a[]={5, 1, 2, 3, 4};
	int n=sizeof(a)/sizeof(int),i;
	int b[n];
	//排序
	mergeSort(a,b,0,n-1);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	for(i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	//结果
	cout<<"逆序对数："<<count<<endl; 
	
	return 0;
} 
