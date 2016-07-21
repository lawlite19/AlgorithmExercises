#include <iostream>
using namespace std;

//每一趟将最大的元素移到最后的位置，然后再移动前面未排序部分，以此类推 
void BubbleSort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++){// n个数排序需要比较n-1趟（0~n-2），当然i<n也是没错，因为当i=n-1时，下面j<n-(n-1)-1=0,不进入下一层for循环 
		for(j=0;j<n-i-1;j++){//因为后面比较的是a[j]和a[j+1],j会+1，所以是j<n-i-1 
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		} 
	}	
} 

int main()
{
	int n=0,a[100],i,data;
	//输入 
	cout<<"请输入待排序数字:(以-1结尾)"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data; 
	}
	//排序 
	BubbleSort(a,n);
	//输出 
	cout<<"n="<<n<<endl; 
	cout<<"排序结果："<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0; 
} 
