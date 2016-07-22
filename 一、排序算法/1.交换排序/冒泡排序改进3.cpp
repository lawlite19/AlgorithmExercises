/*
结合冒泡排序改进的1,2，两端冒泡可以结合记录最后交换的位置，省去不必要的比较次数。 
*/
#include <iostream>
using namespace std;

//交换两个数
void swapNumber(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
} 

void BubbleSortFrontEndAndPos(int *a,int len)
{
	int low=0,high=len-1;
	int i,pos;//pos记录最后交换的位置 
	while(low<high){
		pos=low;//每次初始化为最前面 
		for(i=low;i<high;i++){
			if(a[i]>a[i+1]){
				pos=i;//记录交换的位置 
				swapNumber(&a[i],&a[i+1]);
			}
		}
		high=pos;//修改前面待排序的最后一位位置 
		for(i=high;i>low;i--){
			if(a[i]<a[i-1]){
				pos=i;//记录交换的位置 
				swapNumber(&a[i],&a[i-1]);
			}
		}
		low=pos;//修改下一趟的开始位置 
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
	BubbleSortFrontEndAndPos(a,n);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
