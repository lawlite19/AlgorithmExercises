/*
1、先取一个小于n的整数d1作为第一个增量（通常希尔增量为{N/2, (N/2)/2, ..., 1}，N为元素个数），把文件的全部记录分组。所有距离为d1的倍数的记录放在同一个组中,在各组内进行直接插入排序；
2、取第二个增量d2<d1重复上述的分组和排序，直至所取的增量dt=1，(dt< …<d2<d1)，即所有记录放在同一组中进行直接插入排序为止。
*/ 

#include <iostream>
using namespace std;
 
void swapNum(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void shellSort(int *a,int len)
{
	if(len<=1||a==NULL)
		return;
	int div,i,j;
	for(div=len/2;div>=1;div/=2){//希尔增量（步长） 
		for(i=div;i<len;i++){//i控制每个步长的数遍历到 
			for(j=i;(j-div>=0)&&(a[j]<a[j-div])&&j>=0;j-=div){//特定步长的数若是后面的比前面的小，则交换,中间判断条件需要判断j-div>=0，因为只有j>=0的条件j-div可能越界 
				swapNum(&a[j],&a[j-div]);
				//swapNum(a+j,a+j-div);//这样也是可以的，a是代表数组的首地址，+j表示偏移j个位置，即为a[j]的地址 
			}
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
	shellSort(a,n); 
	//输出
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
} 
