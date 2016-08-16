/*
问题描述：给定字符串，将字符串前面若干字符移动到字符串后面 

暴力法：每次将第一个字符移动到末尾，调用m次即将前m位平移到后面 
*/ 
#include <iostream>
using namespace std;

//实现每次将最前面的一个字母移到最后 
void lowShiftOne(char *s,int len) 
{
	int i;
	char temp=s[0];//记录第一个字符 
	for(i=1;i<len;++i)//后面的字符前移一位 
		s[i-1]=s[i];
	s[len-1]=temp;//将记录的第一个字符放在最后位置 
}
//将前m个字母平移到后面 
void lowRotateString(char *s,int len,int m)
{
	while(m--)//移动m次 
		lowShiftOne(s,len);
}

int main()
{
	char s[100],data;
	int n=0,i;
	//输入字符串 
	cout<<"请输入待旋转字符串（以0结尾）"<<endl;
	while(cin>>data && data!='0'){
		s[n++]=data;
	}
	//旋转 
	lowRotateString(s,n,3);
	//输出
	cout<<"n="<<n<<endl; 
	for(i=0;i<n;++i)
		cout<<s[i]<<" ";
	cout<<endl;
	return 0;
}
 
