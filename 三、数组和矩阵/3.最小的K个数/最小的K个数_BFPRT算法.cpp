/*
问题：输入n个整数，输出其中最小的k个 

一般解法：排序（O(nlogn)）、维护长度为k的数组（O(n*k)）或者维护一个k个元素的堆（O(n*logk)） 

这里采用BFPRT算法★★★：

 
*/
#include <iostream>
using namespace std;

void quickSelect(int *a,int k,int low,int high)
{
	int i,j,pivot;
	
	if(lw)
}

int main()
{
	//输入 
	int *a,n=0,data,k;
	cout<<"请输入数据（以-1结尾）："<<endl; 
	while(cin>>data && data!=-1){
		a[n++]=data;
	} 
	cout<<"请输入K值："<<endl;
	cin>>k;
	
	//输出结果
	cout<<"最小的"<<k<<"个数分别为：";
	quickSelect(a,k,0,n-1); 
	
	return 0;
}
