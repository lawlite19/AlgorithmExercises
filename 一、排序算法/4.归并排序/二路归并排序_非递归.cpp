/* 
非递归思想: 将数组中的相邻元素两两配对。用merge函数将他们排序，
构成n/2组长度为2的排序好的子数组段，然后再将他们排序成长度为4的子数组段，
如此继续下去，直至整个数组排好序。
*/
#include <iostream>
using namespace std;

void mergeSort(int *a,int len)
{
	int i,lowMin,lowMax,highMin,highMax,next;
	int temp[100];
	for(i=1;i<len;i*=2){//步长，为1,2,4,8...... 
		for(lowMin=0;lowMin<len-i;lowMin=highMax){//每个步长的数字进行排序 
			highMin=lowMax=lowMin+i;//lowMin和highMin初始同一位置 
			highMax=highMin+i;//highMax记录下一个步长开始的位置，后续并没有改变highMax的值，只是for循环中指定下一段lowMin的位置 
			if(highMax>len)//如果highMax越界，指定为最大值 
				highMax=len;
			next=0;//每次初始化为0，主要用于操作暂存数组temp的坐标 
			while(lowMin<lowMax && highMin<highMax)//遍历两个段，因为highMax可能不是完整的一段，所以可能提前结束 
				temp[next++]=a[lowMin]>a[highMin] ? a[highMin++] : a[lowMin++];//temp暂存较小的元素，同时较小的元素坐标++ 
			while(lowMin<lowMax)//如果前一段没有遍历完（因为highMin<highMax可能提前结束），highMin记录了一个位置，而lowMax到highMin是可以被覆盖的（因为temp记录了），可以将前一段向后移 
				a[--highMin]=a[--lowMax];
			while(next>0)//将暂存数组中的值继续放 
				a[--highMin]=temp[--next]; 
		}
	}
}

int main()
{
		int n=0,a[100],data,i;
		//输入 
		cout<<"请输出待排序数字（以-1结尾）"<<endl;
		while(cin>>data && data!=-1){
			a[n++]=data;
		} 
		//排序
		mergeSort(a,n);
		//输出
		cout<<"n="<<n<<endl;
		for(i=0;i<n;++i)
			cout<<a[i]<<" ";
		cout<<endl; 
		return 0;
} 
