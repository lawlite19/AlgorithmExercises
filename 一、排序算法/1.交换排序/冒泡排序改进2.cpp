/*
传统冒泡排序只是一端冒泡，可以从两端开始，大的数往后冒泡，小的数往前冒泡，两端相遇则停止。 
*/ 
#include <iostream>
using namespace std;

//交换两个数 
void swapNum(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void BubbleSortFontAndEnd(int *a,int len)
{
	int low=0,high=len-1;//记录两端开始位置 
	int i,temp;
	while(low<high){//若两端相遇，则停止 
		for(i=low;i<high;i++){//大的往后冒泡 
			if(a[i]>a[i+1]){
				swapNum(&a[i],&a[i+1]);
			}
		}
		high--;
		for(i=high;i>low;i--){//小的往前冒泡 
			if(a[i]<a[i-1]){
				swapNum(&a[i],&a[i-1]);
			}
		}
		low++;
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
	BubbleSortFontAndEnd(a,n);
	//输出 
	cout<<"n=1"<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0; 
} 
