/*
问题：输入一个字符串，打印出该字符串中字符的所有排列。

求全排列，就是在交换数的位置，以abc为例
1、固定a，求后面bc的排列：abc，acb，求好后，a和b交换，得到bac
2、固定b，求后面ac的排列：bac，bca，求好后，c放到第一位置，得到cba
3、固定c，求后面ba的排列：cba，cab。 
*/
#include <iostream>
using namespace std;

int count=0;//全局变量，统计全排列个数 

//交换两数 
void swapNum(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

void allPermutation(char *c,int low,int high)
{
	if(high<=1)//元素个数小于1，直接返回 
		return;
	int i,j;
	if(low==high){//low一直扩大，当low扩到high时则打印此排列 
		cout<<(++count)<<":";
		for(i=0;i<=high;++i)
			cout<<c[i];
		cout<<endl;
	}
	else{
		for(j=low;j<=high;++j){
			swapNum(c+j,c+low);//交换两数 
			allPermutation(c,low+1,high);//递归处理其余的 
			swapNum(c+j,c+low);//恢复上次的排列排列 
		}
	}
} 

int main()
{
	//输入 
	char c[100],data;
	int n=0;
	cout<<"请输入字符串（以0结尾）"<<endl;
	while(cin>>data && data!='0'){
		c[n++]=data;
	}
	//全排列 
	cout<<"全排列结果："<<endl;
	allPermutation(c,0,n-1);
	return 0;
}
