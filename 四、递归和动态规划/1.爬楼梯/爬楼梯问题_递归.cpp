/*
问题：一步可以爬1、2或3级台阶，问爬n级台阶有多少种走法

递推式：f(n)=f(n-1)+f(n-2)+f(n-3) 
1、假设爬到n-1级，向上一次走一级即可，所以有f(n-1)种走法 
2、假设爬到n-2级，向上一次走两级即可，所以有f(n-2)种走法 
3、假设爬到n-3级，向上一次走三级即可，所以有f(n-3)种走法 
以上三种情况是不懂得，所以总走法为以上三种情况之和
为什么包含了n-4的情况，因为最多一次走3级，n-4走1,2或3级分别对应以上三种情况，已经计算在内了 
*/ 
#include <iostream>
using namespace std;

//递归求法 
int climbStairs(int n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else if(n==3)
		return 4;
	else 
		return climbStairs(n-1)+climbStairs(n-2)+climbStairs(n-3);
		
}

int main()
{
	//输入 
	int n;
	cout<<"请输入楼梯数："<<endl;
	cin>>n;
	
	//输出结果
	cout<<"共有的走法："<<climbStairs(n)<<endl; 
	
	return 0;
}
