/*
简单选择排序，每趟循环只能确定一个元素排序后的定位。
我们可以考虑改进为每趟循环确定两个元素,选出最小的元素放在前面，最大的元素放在后面 
*/
#include <iostream>
using namespace std;

//交换两数 
void swapNum(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp; 
} 

void selectSort(int *a,int len)
{
	int i,j,min,max;
	for(i=0;i<len/2;i++){//总共趟数减半 
		min=i;//记录最小元素坐标 
		max=i;//记录最大元素坐标 
		for(j=i+1;j<len-i;j++){//j=i+1和j<len-i两头同时缩小，因为每次选出两个元素 
			if(a[j]>a[max]){//如果后面的元素大于max坐标对应的元素，更改max坐标 
				max=j;
				continue;//如果a[j]已经大于a[max]了，代表a[j]不是最小的元素了，不必下面的比较了，continue结束本次循环，继续下次循环 
			}
			if(a[j]<a[min]){//如果后面的元素小于min对应的元素，更改min坐标 
				min=j;
			}
		}
		if(min!=i)//如果min变化了，就将最小的元素交换到前面 
			swapNum(&a[i],&a[min]);
		if(max==i)//***这里需要注意下，如果max==i代表max指向最前面，而前面肯定会将最小的元素交换到最前面，所以此时最大的元素为a[min] 
			swapNum(&a[len-i-1],&a[min]);
		else//否则就正常交换 
			swapNum(&a[len-i-1],&a[max]);
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
	selectSort(a,n);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	
	return 0;
}
