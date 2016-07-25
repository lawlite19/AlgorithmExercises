/*
1）设置两个变量i、j，排序开始的时候：i=0，j=n-1；
2）以第一个数组元素作为关键数据，赋值给key，即key=a[0]；
3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值a[j]，将a[j]和a[i]互换；
4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的a[i]，将a[i]和a[j]互换；
5）重复第3、4步，直到i=j；
*/ 
#include <iostream>
using namespace std;

/* 
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp; 
} 
*/ 
void quickSort(int *a,int left,int right)
{
	if(left>=right)//递归出口 
		return;
	int i=left;
	int j=right; //i,j相当于两头指针，移动 
  	int key=a[left];//第一个元素作为枢轴 
	while(i<j){
		while(i<j&&key<=a[j])
			j--;//前移 
		a[i]=a[j];//将比第一个小的移到低端,这里换为交换两个数也是可以的，为什么直接将a[j]的值赋给a[i]也是可以的，因为key=a[left]将最左端的值记录下了，所以a[i]可以被覆盖，这也是为什么从后往前搜索（j--），就可以将小于key的放在a[i]上 
		//swap(&a[i],&a[j]);
		while(i<j&&key>=a[i])
			i++;//后移 
		a[j]=a[i];//将比第一个大的移到高端
		//swap(&a[i],&a[j]);
	}
	a[i]=key;
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
}

int main()
{
	int n=0,data,a[100],i;
	//输入
	cout<<"请输入待排序数字（以-1结尾）"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//排序
	quickSort(a,0,n-1);//n个元素，末位为a[n-1] 
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
 
