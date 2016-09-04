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
#include <vector>
using namespace std;

//两个矩阵相乘 
vector<vector<int> > muliMatrix(vector<vector<int> > m1,vector<vector<int> > m2)
{
	vector<vector<int> > result(m1.size());//声明一个保存结果的二维向量 
	int res; //用于存储m1中每一行乘以m2中每一列的结果，最后放到result中 
	
	for(int i=0;i<m1.size();++i)
		for(int j=0;j<m2[0].size();++j){
			res=0;//每次初试为0 
			for(int k=0;k<m2.size();++k)
				res+=m1[i][k]*m2[k][j];//计算结果 
			result[i].push_back(res);//放入 
		}
	
	return result;
}
//矩阵的n次方 
vector<vector<int> > matrixPower(vector<vector<int> > base,int n)
{
	vector<vector<int> > result(base.size());//声明一个保存结果的二维向量 
	for(int i=0;i<base.size();++i)//初始为单位矩阵 {1,0,0,1} 
		for(int j=0;j<base.size();++j){
			if(i==j)
				result[i].push_back(1);
			else
				result[i].push_back(0);
		}	
	
	vector<vector<int> > tmp(base.size());//声明一个临时二维向量 
	for(int i=0;i<base.size();++i)//将base中数的拷贝到其中 
		for(int j=0;j<base.size();++j){
			tmp[i].push_back(base[i][j]);
		}	
	
	for(;n!=0;n>>=1){//n对应的二进制一直右移，直到为0
		if(n&1)//n&1不为0（与&运算两个1才为1），说明n的二进制最后为1
			result=muliMatrix(result,tmp);//所以计算矩阵相乘 
		tmp=muliMatrix(tmp,tmp);//同时tmp矩阵平方，每右移1位则tmp开平方 
	}

	return result;
}
//计算结果 
int allRectCover(int n)
{
	if(n<1)
		return 0;
	if(n==1 || n==2)
		return n;
	
	vector<vector<int> > result(2);//开辟result的二维向量，每一维大小为2 （注意vector后面两个`> >`之间要有空格） 
	vector<vector<int> > base(2);

	base[0].push_back(1);//初始化base矩阵的值为{1,1,1,0} 
	base[0].push_back(1);
	base[1].push_back(1);
	base[1].push_back(0);

	result=matrixPower(base,n-2);//求base的n-2次方 

	return 2*result[0][0]+result[1][0];	//计算结果 
}

int main()
{
	//输入
	cout<<"请输入n的值"<<endl;
	int n;
	cin>>n;
	
	cout<<"总方法数为："<<allRectCover(n)<<endl; 
	
	return 0;
}
