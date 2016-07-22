/*
改进冒泡排序1，设置pos记录每趟排序最后交换的位置，因为后面的数据如果没有交换，
说明数据是排好序的。 
*/
#include <iostream>
using namespace std;

void BubbleSortWithPos(int *a,int len){
	int i=len-1,//初始第一趟排序为最后位置 
	j,temp;
	while(i>0){
		int pos=0;//每趟排序初始值为0 
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				pos=j;//记录交换的位置 
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		i=pos;//记录下一趟交换的最后位置 
	} 
}

int main()
{
	int n=0,a[100],i,data;
	//输入 
	cout<<"请输入待排序数字（以-1结束）"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//排序
	BubbleSortWithPos(a,n);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" "; 
	} 
	cout<<endl;
	return 0; 
} 
