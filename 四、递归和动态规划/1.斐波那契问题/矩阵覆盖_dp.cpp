/*
问题：用n个2*1的小矩形横着或竖着覆盖2*n的大矩形，共有多少种方法？

1、考虑当为n-1时，竖着放一个即可，为f(n-1)种
2、当为n-2时，为和n-1不重复，所以横着放两个即可，为f(n-2)种，
3、所以f(n)=f(n-1)+f(n-2)

为什么n-3不继续推，因为n-3时再放1个或2个就和n-2和n-1重复了 
*/
#include <iostream>
using namespace std;

//使用数组推算 
int allRectCover1(int n)
{
	int result,a[n];
	a[1]=1;//n=1时共1种方法 
	a[2]=2;//n=2时共2种方法 
	for(int i=3;i<=n;++i){//从3开始遍历 
		result=a[i-1]+a[i-2];//计算result 
		a[i]=result;//设置下一步 
	} 
	
	return result;
} 

//使用变量推算 
int allRectCover2(int n)
{
	int result=2;//初始值为n=2时共2种方法 
	int pre=1;//初始值前一步为1 
	int temp;//记录当前结果的临时变量 

	for(int i=3;i<=n;++i){//从3开始遍历 
		temp=result;//记录下当前result 
		result+=pre;//计算结果 
		pre=temp;	//将前一步置为计算的结果 
	}
	
	return result;
} 

int main()
{
	//输入
	int n;
	cout<<"请输入n的值"<<endl;
	cin>>n;
	
	//cout<<"总方法数为(使用数组推算)："<<allRectCover1(n)<<endl; 
	cout<<"总方法数为(使用几个变量推算)："<<allRectCover2(n)<<endl; 
	return 0;
} 
