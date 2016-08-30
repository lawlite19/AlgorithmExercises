/*
问题：输入n个整数，输出其中最小的k个 

一般解法：排序（O(nlogn)）、维护长度为k的数组（O(n*k)） 
这里
1、采用大根堆，
2、遍历k到n，若是小于堆顶，则将堆顶元素替换掉，重新调整为大顶堆 
*/
#include <iostream>
using namespace std;

//调整堆 
void adjustHeap(int *a,int i,int len)
{
	int temp=a[i];//记录要调整的节点 
	int child=2*i+1;//节点的左孩子坐标 
	while(child<len){
		if(child+1<len&&a[child]<a[child+1]){//判断是左孩子大还是右孩子大 
			child++;//若是右孩子大，则定位到右孩子 
		}
		if(a[i]<a[child]){//若是节点小于较大的孩子，则将孩子上移 
			a[i]=a[child];
			i=child;//重新设置节点坐标，为下面的调整做准备 
			child=2*i+1;//继续计算其左孩子 
		}
		else//若是节点大于其孩子节点，直接退出循环 
			break;
		a[i]=temp;//将节点放在调整的孩子节点上 
	} 
} 
//初始建堆 
void initHeap(int *a,int k)
{
	for(int i=(k-2)/2;i>=0;--i){//有孩子的节点的最后位置是(k-2)/2，往前推,因为这里下标从0开始的 
		adjustHeap(a,i,k);
	}
} 
//求最小的K个数 
void getTopK(int *a,int k,int len)
{
	initHeap(a,k);//建立前K个元素的堆 
	for(int i=k;i<len;++i){//遍历后面的元素 
		if(a[i]<a[0]){//若是有比堆顶(a[0])小的元素 
			a[0]=a[i];//将堆顶替换 
			adjustHeap(a,0,k); //调整堆 
		}
	}
	
	for(int i=0;i<k;++i)//输出前K个元素，即为结果 
		cout<<a[i]<<" ";
	cout<<endl;
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
	getTopK(a,k,n);
	return 0;
} 
