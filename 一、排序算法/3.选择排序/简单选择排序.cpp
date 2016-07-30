/*
第一趟，从n个记录中找出关键码最小的记录与第一个记录交换；
第二趟，从第二个记录开始的n-1 个记录中再选出关键码最小的记录与第二个记录交换；
以此类推.....
第i 趟，则从第i 个记录开始的n-i+1 个记录中选出关键码最小的记录与第i 个记录交换，
直到整个序列按关键码有序。
*/ 
#include <iostream>
using namespace std;

void simpleSelectSort(int *a,int len)
{
	int i,j,k,temp;
	for(i=0;i<len;i++){
		k=i;//暂存第i个元素坐标，暂认为最小的元素坐标 
		for(j=i+1;j<len;j++){//在i+1之后的元素中找最小的元素，用k记录 
			if(a[k]>a[j])
				k=j;
		}
		if(k!=i){//k值变化说明之前假设的不是最小的元素，交换a[k]和a[i] 
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}
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
	simpleSelectSort(a,n);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
