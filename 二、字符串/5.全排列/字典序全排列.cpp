/*
问题：已知字符串里的字符是互不相同的，现在任意组合，比如ab，则输出aa，ab，ba，bb，按照字典序排列 

*/
#include <iostream>
using namespace std;

int count=0;//全局变量，统计排列个数 

void notSimpleAllPermutation(char *result,char *s,int len,int resPos)
{
	int i;
	if(resPos>=len)//如果处理位置到最后，就输出字符串 
		cout<<(++count)<<":"<<result<<endl;
	else{
		for(i=0;i<len;++i){//遍历 
			result[resPos]=s[i];//result用于存储结果 
			notSimpleAllPermutation(result,s,len,resPos+1);
		}
	}
}

int main()
{
	//输入 
	char *s,data,result[100];
	int n=0;
	cout<<"请输入字符（以0结尾）"<<endl;
	while(cin>>data && data!='0'){
		s[n++]=data;
	}
	
	//输出结果
	notSimpleAllPermutation(result,s,n,0); 
	return 0;
}
