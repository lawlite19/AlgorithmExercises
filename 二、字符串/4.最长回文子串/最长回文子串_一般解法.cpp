/*
问题：求一个字符串的最长回文子串的长度

遍历字符串，以当前字符往左右扩展比较即可，记录当前最大长度
需要注意的是左右扩展有两种情况，一种是奇数个字符，另一种是偶数个字符 
*/ 
#include <iostream>
#include <string>
using namespace std;

int longPalindrome(string &s,int len)
{
	int i,j,max=0,temp;
	if(len<1)
		return 0;
	for(i=0;i<len;++i){//遍历字符 
		for(j=0;(i-j>=0) && (i+j<len);++j){//奇数个字符，以当前i为中心扩展 
			if(s[i-j]!=s[i+j])//过程中不相等则break 
				break;
			temp=j*2+1;//得到长度 
		}
		if(temp>max)
			max=temp;//更改最大值 
		for(j=0;(i-j>=0) && (i+j+1<len);++j){//偶数个字符，往右多扩展一个 
			if(s[i-j]!=s[i+j+1])//不相等则退出 
				break;
			temp=j*2+2;
		}
		if(temp>max)
			max=temp;//更改最大值 
	}
	return max;
} 

int main()
{
	//输入 
	string s;
	cout<<"请输入字符串"<<endl;
	cin>>s;
	//输出长度结果
	cout<<"结果："<<longPalindrome(s,s.length())<<endl;
	return 0;
} 
