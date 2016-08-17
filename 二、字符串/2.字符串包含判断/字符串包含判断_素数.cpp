/*
问题：判断A字符串是否包含B字符串（A：12,B：111同样表示包含） 

1、首先将26个素数一一对应字符a到z 
2、遍历A字符串，求每个字符对应素数的乘积
3、遍历B字符串，判断此乘积能够被字符串中每个字符对应的素数整除 
时间复杂度为O（m+n） 
(这里只对应了26个小写英文字符，另外乘积可能很大，有越界风险，实际应用价值不大)
*/
#include <iostream>
#include <string>
using namespace std;

bool stringContain(string &s1,string &s2)
{
	const int p[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	long long f=1;
	int i,x;
	for(i=0;i<s1.length();++i){//遍历s1 
		x=p[s1[i]-'a'];// 得到每个字符对应的素数 
		if(f%x)//如果当前计算乘积不能被对应的素数整除，就接着计算（重复的元素不用计算，因为后面判断不会改变这个乘积，只是判断能否整除，重复的也没关系） 
			f*=x;
	}
	for(i=0;i<s2.length();++i){//遍历s2 
		x=p[s2[i]-'a'];//到每个字符对应的素数
		if(f%x)//如果不能被整除就返回false 
			return false;
	}
	return true;
} 

int main()
{
	//输入
	string s1,s2;
	cout<<"请输入字符串s1:"<<endl;
	cin>>s1; 
	cout<<"请输入字符串s2:"<<endl;
	cin>>s2; 
	//输出结果 
	cout<<"结果："<<stringContain(s1,s2)<<endl;
	return 0;
} 
