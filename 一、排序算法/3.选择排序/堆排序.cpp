/*
1、先将初始文件a[1...n-1]建成一个大根堆，此堆为初始的无序区
2、再将关键字最大的记录a[1]（即堆顶）和无序区的最后一个记录a[n-1]交换，由此得到新的无序区a[1..n-2]和有序区a[n-1]
3、由于交换后新的根a[1]可能违反堆性质，故应将当前无序区R[1...n-2]调整为堆。然后继续2的操作 

1' 调整堆过程 
比较节点i和它的孩子节点left(i),right(i)，选出三者最大(或者最小)者，如果最大（小）值不是节点i而是它的一个孩子节点，那边交换节点i和该节点
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
void initHeap(int *a,int len)
{
	int i;
	for(i=(len-1)/2;i>=0;i--){//有孩子的节点的最后位置是(len-1)/2，往前推 
		adjustHeap(a,i,len);
	}
}

/*堆排序
建立的是大顶堆，输出为从小到大。
因为每次调整是将最大的（堆顶）元素与最后的元素交换，
然后排除最后元素，继续调整堆，所以每次都是将最大的元素放在最后，最后输出即为从小到大 
*/
void heapSort(int *a,int len)
{
	int i,temp;
	initHeap(a,len);//建堆 
	for(i=len-1;i>=0;i--){
		temp=a[0];//交换堆顶和最后的元素 
		a[0]=a[i];
		a[i]=temp;
		adjustHeap(a,0,i);//排除最后一个元素调整堆 
	}
}

int main()
{
	int n=0,a[100],i,data;
	//输入
	cout<<"请输入待排序的数字（以-1结尾）"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//排序
	heapSort(a,n);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
} 
