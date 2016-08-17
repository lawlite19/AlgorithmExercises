/*
问题：回文即正着读与倒着读一样，比如12321

前后两个指针遍历比较即可 
*/
#include <iostream>
#include <string>
using namespace std;
//判断字符串 
bool isPalindromeString(string &s,int len)
{
	if(len<1)
		return false;
	int low=0,high=len-1;//low指向头，high指向尾 
	while(low<high){//直到前后相遇 
		if(s[low]!=s[high])//不相等就返回false 
			return false;
		++low;
		--high; 
	}
	return true;
}
//判断字符数组
bool isPalindromeChars(char *c,int len)
{
	if(c==NULL || len<1)
		return false;
	char *front,*back;//定义前后两个指针 
	front=c;//front指向头 
	back=c+len-1;//back指向尾 
	while(front<back){
		if(*front != *back)//取出字符进行比较，不相等返回 
			return false;
		++front;
		--back;
	}
	return true;
}
int main()
{
//===字符串 
	//输入
	string s;
	cout<<"请输入字符串:"<<endl;
	cin>>s;
	//输出结果 
	cout<<"字符串结果1:"<<isPalindromeString(s,s.length())<<endl;
	
//===字符数组 
	//输入
	char c[100],data,n=0;
	cout<<"请输入字符数组（以0结尾）"<<endl;
	while(cin>>data && data!='0'){
		c[n++]=data;
	}
	//输出结果 
	cout<<"字符数组结果2:"<<isPalindromeChars(c,5)<<endl;
	return 0;
}
