/*
问题： 给定一个 N*2 的二维数组，看作是一个个二元组，例如[[a1,b1],[a2,b2],[a3,b3]]，
		规定：一个如果想把二元组甲放在二元组乙上，甲中的 a 值必须大于乙中的 a 值，甲中的 b
		值必须大于乙中的 b 值。如果在二维数组中随意选择二元组，请问二元组最多可以往上摞
		几个？
		例如：[[5,4],[6,4],[6,7],[2,3]], 最大数量可以摞 3 个，[2,3] => [5,4] => [6,7]

O（NlogN）解法：（借助最长递增子序列的算法原型****） 
1、将二维数组按照第1个元素递增排列
2、在第一个元素相等的前提下，将二维数组按照第2个元素递减排列
3、遍历二维数组，按照第2个元素使用递增子序列的算法即可（因为第一个元素已经有序了） 

为什么这样是可以的？
因为在X相等的每一组中最多选一个，又因为Y是倒序，所以递增子序列中每一组最多也就选一个 

 
说明：这里声明一个类Dot，包含两个元素对应二维数组中的值 （在leetcode上通过） 
*/ 
#include <stdio.h>
using namespace std;
class Dot{//声明Dot类，存储二维数组 
	public:
		int x;
		int y;
};
//按照X从小到大快速排序 
void quickSortByX(Dot dots[],int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	int k=dots[low].x;
	Dot temp=dots[low];
	while(i<j){
		while(i<j && dots[j].x>=k)
			--j;
		dots[i]=dots[j];
		while(i<j && dots[i].x<=k)
			++i;
		dots[j]=dots[i];
	}
	dots[i]=temp;
	quickSortByX(dots,low,i-1);
	quickSortByX(dots,i+1,high);
}
//按照Y从大到小快速排序 
void quickSortByY(Dot dots[],int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	int k=dots[low].y;
	Dot temp=dots[low];
	while(i<j){
		while(i<j && dots[j].y<=k)
			--j;
		dots[i]=dots[j];
		while(i<j && dots[i].y>=k)
			++i;
		dots[j]=dots[i];
	}
	dots[i]=temp;
	quickSortByY(dots,low,i-1);
	quickSortByY(dots,i+1,high);
}
//得到最终的排序结果，在X相等的前提下按Y倒序 
void sort(Dot dots[],int len){
	int indexLow=0;//用于记录X相等情况下的开始位置 
	int indexHigh=0;//结束位置 
	for(int i=1;i<=len;++i){//遍历***（这里是i<=len,因为如果倒数第二个和最后一个相等的话，就不会执行排序了） 
		if(dots[i].x==dots[i-1].x)//
			indexHigh=i;
		else{
			quickSortByY(dots,indexLow,indexHigh);
			indexLow=i;
		}
	}
}

//使用最长递增子序列的原型算法，计算Y的即可（具体请看最长递增子序列的dp优化部分） 
int maxEnvelope(Dot *dots,int len)
{
	quickSortByX(dots,0,len-1);
	sort(dots,len);
	int end[len];
	int dp[len];
	end[0]=dots[0].y;
	int right=0;
	int l=0;
	int m=0;
	int r=0;
	for(int i=0;i<len;++i){
		l=0;
		r=right;
		while(l<=r){
			m=(l+r)/2;
			if(end[m]<dots[i].y)
				l=m+1;
			else
				r=m-1;
		}
		end[l]=dots[i].y;
		right=right>l?right:l;
	}
	return right+1;
}

int main()
{
	//int a[8][2]={{1,2},{2,3},{3,4},{1,1},{5,7},{5,3},{2,8},{6,9}};
	//int a[][2]={1,3,3,5,6,7,6,8,8,4,9,5};
	int a[][2]={1,15,7,18,7,6,7,100,2,200,17,30,17,45,3,5,7,8,3,6,3,10,7,20,17,3,17,45};
	int len=sizeof(a)/sizeof(a[0]);
	Dot dots[len];
	for(int i=0;i<len;++i){
		dots[i].x=a[i][0];
		dots[i].y=a[i][1];
	}
	printf("最多可以摞的个数：%d",maxEnvelope(dots,len));

	return 0;
} 
