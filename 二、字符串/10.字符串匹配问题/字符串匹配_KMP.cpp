/*
问题：字符串匹配，即在字符串s中查找字符串m是否存在，返回匹配后在s中的首位置，否则返回-1 
		leetcode28(Accepted). Implement strStr()
		 
KMP算法：
*/ 
#include <iostream>
using namespace std;

//求next数组 
void getNext(string &m,int *next,int len)
{
	if(m.length()==1){//若m只有一位，直接设置next[0]为-1，返回，不用判断了 
		next[0]=-1;
		return;
	}
	
	next[0]=-1;//初始next[0]=-1,next[1]=0 
	next[1]=0;
	int pos=2;//遍历的当前字符位置 
	int cn=0;//记录每次往前跳的字符位置 
	while(pos<len){//遍历 
		if(m[pos-1]==m[cn])//若是当前遍历前一个字符与cn位置字符相等，next对应值++，同时pos++，++cn 
			next[pos++]=++cn;
		else if(cn>0)//否则的话cn没跳到最前面，就接着往前跳 
			cn=next[cn];
		else
			next[pos++]=0;//否则就为-1,同时pos++ 
	}
		
}
//匹配 
int strStr(string &s,string &m)
{
	if(m.length()>s.length())
		return -1;
		
	int len=m.length();
	int next[len];
	getNext(m,next,len); //求next数组 
	
	int si=0;
	int mi=0;
	while(si<s.length() && mi<m.length()){//遍历s和m 
		if(s[si]==m[mi]){//如果相等，对应位置都++ 
			++si;
			++mi;
		}
		else if(next[mi]==-1)//如果对应的mi出next值为-1，遍历s的下一个位置 
			++si;
		else
			mi=next[mi];//否则就往前推m 
	}
	
	return mi==m.length() ? si-mi : -1; //如果m遍历到最后，返回匹配的开始位置，否则返回-1 
} 

int main()
{	
	string s,m;
	cout<<"请输入两个字符串："<<endl;
	cin>>s>>m;
	//s="";
	//m="";
	cout<<"匹配的开始位置为："<<strStr(s,m)<<endl; 
	
	return 0;
}
