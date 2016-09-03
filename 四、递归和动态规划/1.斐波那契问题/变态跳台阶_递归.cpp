/*
问题：一只青蛙可以跳1到n级台阶，求跳上n级台阶的总跳法 

f(1)=1;
f(2)=f(1)+f(0);
f(3)=f(2)+f(1)+f(0);
......
f(n-1)=f(n-2)+f(n-3)+...+f(0)
f(n)=f(n-1)+f(n-2)+...+f(0)
	=f(n-1)+f(n-1)
	=2*f(n-1)
 所以得到递推式：
 	f(n)=2*f(n-1) 
*/
#include <iostream>
using namespace std;

int climbStairs(int n)
{
	if(n<1)
		return 0;
	else if(n==1)
		return 1;
	else return 2*climbStairs(n-1);
}

int main()
{
	//输入 
	int n;
	cout<<"请输入台阶数："<<endl;
	cin>>n;
	
	cout<<"总跳法为："<<climbStairs(n)<<endl; 
	
	return 0;
} 
