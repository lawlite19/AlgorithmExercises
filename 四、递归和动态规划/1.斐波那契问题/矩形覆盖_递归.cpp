/*
问题：用n个2*1的小矩形横着或竖着覆盖2*n的大矩形，共有多少种方法？

1、考虑当为n-1时，竖着放一个即可，为f(n-1)种
2、当为n-2时，为和n-1不重复，所以横着放两个即可，为f(n-2)种，
3、所以f(n)=f(n-1)+f(n-2)

为什么n-3不继续推，因为n-3时再放1个或2个就和n-2和n-1重复了 
*/
#include <iostream>
using namespace std;

int allRectCover(int n)
{
	if(n<1)
		return 0;
	else if(n==1||n==2)//当n=1是为1种方法，当n=2时为两种方法  
		return n;
	else 
		return  allRectCover(n-1)+allRectCover(n-2);
} 

int main()
{
	//输入
	int n;
	cout<<"请输入n的值"<<endl;
	cin>>n;
	
	cout<<"总方法数为："<<allRectCover(n)<<endl; 
	
	return 0;
} 
