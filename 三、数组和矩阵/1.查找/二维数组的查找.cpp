/*
问题：一个二维数组，每行从左往右递增，每列从上往下递增，给定一个数，判断这个数是否出现数组中

从左下角开始找，比它大则往右，比它小则往上 
*/ 
#include <iostream>
using namespace std;

bool isExist(int a[][4],int rowCount,int colCount,int number)//二维数组作形参也可以是(*a)[4]，二维必须指定长度 
{
	
	int i,j;
	for(i=rowCount-1,j=0;i>=0 && j<colCount;){//从左下角开始 
		if(number>a[i][j])//往右 
			++j;
		else if(number<a[i][j])//往上 
			--i;
		else//找到，返回true 
			return true; 
	} 
	return false;
}

int main()
{
	//初始二维数组 
	int a[3][4]={{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}};
	int n,rowCount,colCount; 
	cout<<"二维数组为："<<endl;
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j)
			cout<<a[i][j]<<" ";
		cout<<endl; 
	}
	//求行数和列数
	rowCount=sizeof(a)/sizeof(a[0]);//sizeof(a)为所有元素字节数，sizeof(a[0])为一行元素字节数 
	colCount=sizeof(a[0])/sizeof(int);
	
	cout<<endl<<"请输入一个数:"<<endl; 
	cin>>n;
	
	//输出 
	cout<<"结果:"<<isExist(a,rowCount,colCount,n)<<endl;
	
	return 0;
}
