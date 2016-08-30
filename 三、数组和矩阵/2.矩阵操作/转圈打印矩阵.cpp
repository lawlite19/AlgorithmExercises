/*
问题：转圈打印矩阵

1、（topRow,topCol）记录左上角元素位置，（downRow,downCol）记录右下角元素位置
2、每次打印一圈后 topRow++,topCol++， downRow--,downCol--
3、若是左上角任一坐标跑到右下角对应坐标下面，则打印完毕 
*/ 
#include <iostream>
using namespace std;

//打印子矩阵的一圈 
void printCircle(int a[][4],int topRow,int topCol,int downRow,int downCol)
{
	if(topRow==downRow)//如果只剩一行，直接打印 
		for(int i=topCol;i<=downCol;++i)
			cout<<a[topRow][i]<<" ";
	else if(topCol==downCol)//如果只剩一列，直接打印
		for(int i=topRow;i<=downRow;++i)
			cout<<a[i][topCol]<<" ";
	else{//其他情况 
		int curCol=topCol,curRow=topRow;//声明两个变量分别移动打印（相当于两个指针转圈移动） 
		while(curCol!=downCol)//往右，遍历到右下角的列号,最后curCol会移动到当前行最后（并不打印当前行最后一个元素，curCol++到downCol后退出了while，这样可以最后并不会打印（topRow,topCol）这个元素） 
			cout<<a[topRow][curCol++]<<" ";
		while(curRow!=downRow)//往下，遍历到右下角的行号，最后curRow会移动到列的最后 
			cout<<a[curRow++][downCol]<<" "; 
		while(curCol!=topCol)//往左，遍历到左上角的列号，最后curCol会移动到列的最前 
			cout<<a[downRow][curCol--]<<" "; 
		while(curRow!=topRow)//往上， 
			cout<<a[curRow--][topCol]<<" "; 
	}
}
//主方法 
void spiralOrderPrint(int a[][4],int rowCount,int colCount)
{
	int topRow=0;
	int topCol=0;
	int downRow=rowCount-1;
	int downCol=colCount-1;//获取左上角和右下角的坐标 
	while(topRow<=downRow && topCol<=downCol)//任一坐标超过则结束打印 
		printCircle(a,topRow++,topCol++,downRow--,downCol--);//打印一圈主函数 
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
