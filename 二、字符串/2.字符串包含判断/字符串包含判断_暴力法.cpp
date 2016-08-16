/*
判断A字符串是否包含B字符串

暴力法：遍历，复杂度为O（m*n） 
*/ 

#include <iostream>
#include <string>
using namespace std;

bool stringContain(string &a,string &b)
{
	int i,j;
	for(i=0;i<b.length();++i){//判断a是否包含b，首先遍历b，然后遍历a，若是在a中没有找到就返回false 
		for(j=0;j<a.length() && b[i]!=a[j];++j);//b[i]!=a[j]继续遍历找， 
		if(j>=a.length())//没有找到就返回false 
			return false;
	}
	return true;
} 

int main()
{
	string s1,s2;
	int n1=0,n2=0;
	//输入
	cout<<"请输入第一个字符串："<<endl;
	cin>>s1;
	cout<<"请输入第二个字符串：（以0结尾）"<<endl;
	cin>>s2;
	//输出判断结果
	cout<<"结果："<<stringContain(s1,s2)<<endl;
	return 0;
}
