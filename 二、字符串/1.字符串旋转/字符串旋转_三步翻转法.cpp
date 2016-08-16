/*
三次翻转法：
比如：abcdef==>defabc
1、abc==>cba
2、def==>fed
3、cbafed==>defabc
*/ 
#include <iostream>
using namespace std;

//翻转 
void reverseString(char *s,int low,int high)
{
	char temp;
	while(low<high){
		temp=s[low];
		s[low++]=s[high];
		s[high--]=temp;
	}
}
//调用三次翻转 
void lowRotateString(char *s,int len,int m)
{
	m%=len;//若是m移动大于len，等价于m%len 
	reverseString(s,0,m-1);
	reverseString(s,m,len-1);
	reverseString(s,0,len-1);
}

int main()
{
	char s[100],data;
	int n=0,i;
	//输入
	cout<<"请输入待旋转字符串（以0结尾）"<<endl;
	while(cin>>data && data!='0'){
		s[n++]=data;
	}
	//旋转
	lowRotateString(s,n,3);
	//输出
	cout<<"n="<<n<<endl;
	for(i=0;i<n;++i){
		cout<<s[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
