/*
问题：用n个2*1的小矩形横着或竖着覆盖2*n的大矩形，共有多少种方法？

1、考虑当为n-1时，竖着放一个即可，为f(n-1)种
2、当为n-2时，为和n-1不重复，所以横着放两个即可，为f(n-2)种，
3、所以f(n)=f(n-1)+f(n-2)

为什么n-3不继续推，因为n-3时再放1个或2个就和n-2和n-1重复了 

矩阵转化： 
令（f(n),f(n-1)）=(f(n-1),f(n-2))*|a b| 
								  |c d|	，根据初始值可以求出abcd矩阵
所以最终可以得到 (f(n),f(n-1))=	(f(2),f(1))*|a b|^(n-2)
								  			|c d|	
而矩阵的n次方计算可以在O(logn)时间复杂度得到 
将f(1)=1,f(2)=2,f(3)=3,f(4)=5代入可以计算出矩阵 
*/
#include <iostream>
using namespace std;

class Matrix{//定义一个类或结构体，方便返回矩阵对象 
	public://这里我将属性定义为public的了，方便直接操作 
		int m[2][2];
		int row;
		int col;
};

//两个矩阵相乘 
Matrix muliMatrix(Matrix m1,Matrix m2) 
{
	Matrix result;
	result.row=m1.row;
	result.col=m2.col;//设置两个矩阵计算的行数和列数
	//将矩阵中的值初始化为0 
	for(int i=0;i<result.row;++i)
		for(int j=0;j<result.col;++j)
			result.m[i][j]=0;
	//两个矩阵相乘		
	for(int i=0;i<m1.row;++i){//遍历m1的行 
		for(int j=0;j<m2.col;++j){//遍历m2的列 
			for(int k=0;k<m2.row;++k){//遍历m1的列或者m2的行 
				result.m[i][j]+=m1.m[i][k]*m2.m[k][j];//对应相乘相加 
			}
		}
	}
	return result;
}

Matrix matrixPower(Matrix base,int n)
{
	//初始化矩阵为一个单位矩阵 
	Matrix result;
	result.col=base.col;
	result.row=base.row; 
	for(int i=0;i<result.row;++i)
		result.m[i][i]=1;
	//初始化暂存矩阵为传递过来要计算的base矩阵 
	Matrix tmp;
	tmp.row=base.row;
	tmp.col=base.col;
	for(int i=0;i<tmp.row;++i)
		for(int j=0;j<tmp.col;++j)
			tmp.m[i][j]=base.m[i][j];
			
	//计算base的n次方，将结果存储到result中
	for(;n!=0;n >>= 1){//n对应的二进制一直右移，直到为0 
		if(n&1)//n&1不为0（与&运算两个1才为1），说明n的二进制最后为1 
			result=muliMatrix(result,tmp);//所以计算矩阵相乘 
		
		tmp=muliMatrix(tmp,tmp);//同时tmp矩阵平方，每右移1位则tmp开平方 
	}
	return result;
}

int allRectCover(int n)
{
	if(n<1)
		return 0;
	if(n==1 || n==2)
		return n;
	//设置矩阵的初始值为{1,1,1,0} 
	Matrix base;
	base.row=2;
	base.col=2;
	base.m[0][0]=1;base.m[0][1]=1;base.m[1][0]=1;base.m[1][1]=0;
	
	Matrix result;
	result.row=2;
	result.col=2;
	
	result=matrixPower(base,n-2);//求base的n-2次方 
	//结果为（f(n),f(n-1)）=（f(2),f(1)）=(2,1)*base^(n-2) 
	return 2*result.m[0][0]+result.m[1][0];
}

int main()
{
	//输入 
	int n;
	cout<<"请输入n的值"<<endl;
	cin>>n;
	//输出 
	cout<<"总覆盖方法数为："<<allRectCover(n)<<endl;
	return 0;
} 
