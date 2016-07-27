#include <iostream>
using namespace std;

void insertSortRecursion(int *a,int index,int len)
{
	if(index>=len)//递归出口 
		return;
	int key=a[index];//记录当前待插入的元素 
	int i;
	for(i=index-1;i>=0&&key<a[i];i--){//元素后移 
		a[i+1]=a[i];
	}
	a[i+1]=key;//将元素插入到对应位置 
	insertSortRecursion(a,index+1,len);//递归处理之后的 
}

int main()
{
	int n=0,a[100],i,data;
	//输入
	cout<<"请输入待排序数字（以-1结尾）"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//排序
	insertSortRecursion(a,1,n);
	//输出
	cout<<"n="<<n<<endl; 
	for(i=0;i<n;i++){
		cout<<a[i]<<" "; 
	} 
	cout<<endl;
	return 0;
} 
