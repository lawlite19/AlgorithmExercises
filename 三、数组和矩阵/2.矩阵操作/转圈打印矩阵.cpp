/*
问题：转圈打印矩阵

1、（topRow,topCol）记录左上角元素位置，（downRow,downCol）记录右下角元素位置
2、每次打印一圈后 topRow++,topCol++， downRow--,downCol--
3、若是左上角坐标跑到右下角坐标下面，则打印完毕 
*/ 
#include <iostream>
using namespace std;

//打印子矩阵的一圈 
void printCircle(int a[][4],int topRow,int topCol,int downRow,int downCol)
{
	if(topRow==downRow)
		for(int i=topCol;i<=downCol;++i)
			cout<<a[topRow][i]<<" ";
	else if(topCol==downCol)
		for(int i=topRow;i<=downRow;++i)
			cout<<a[i][topCol]<<" ";
	else{
		int curCol=topCol;
		int curRow=topRow;
		while(curCol!=downCol)
			cout<<a[topRow][curCol++]<<" ";
		while(curRow!=downRow)
			cout<<a[curRow++][downCol]<<" "; 
		while(curCol!=topCol)
			cout<<a[downRow][curCol--]<<" "; 
		while(curRow!=topRow)
			cout<<a[curRow--][topCol]<<" "; 
	}
}
//主方法 
void spiralOrderPrint(int a[][4],int rowCount,int colCount)
{
	int topRow=0;
	int topCol=0;
	int downRow=rowCount-1;
	int downCol=colCount-1;
	while(topRow<=downRow && topCol<=downCol)
		printCircle(a,topRow++,topCol++,downRow--,downCol--);
}

int main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	cout<<"矩阵为："<<endl;
	int rowCount=sizeof(a)/sizeof(a[0]);//求行数 
	int colCount=sizeof(a[0])/sizeof(int);//求列数 
	//显示矩阵 
	for(int i=0;i<rowCount;++i){
		for(int j=0;j<colCount;++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	} 
	//输出结果
	cout<<"结果为："<<endl;
	spiralOrderPrint(a,rowCount,colCount);
	 
	return 0;
}
