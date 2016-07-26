/*
1.初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1
2.将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。
3.i++并重复第二步直到i==n-1。排序完成。
*/ 

#include <iostream>
using namespace std;

void StraightInsertSort(int *a,int len)
{
	int i,j,temp;
	for(i=1;i<len;i++){
		if(a[i]<a[i-1]){
			temp=a[i];//记录要插入的数字 
			for(j=i-1;j>=0&&a[j]>temp;j--){//元素后移 
				a[j+1]=a[j];
			} 
			a[j+1]=temp;//插入对应的位置 
		}
	}
}

int main()
{
	int n=0,a[100],data,i;
	//输入
	cout<<"请输入待排序数字（以-1结尾）"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//排序
	StraightInsertSort(a,n);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
} 
