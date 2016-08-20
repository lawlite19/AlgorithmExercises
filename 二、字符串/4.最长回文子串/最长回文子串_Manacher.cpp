/*
问题：求一个字符串的最长回文子串的长度

Manacher算法 ——时间复杂度O（n）
1、首先通过在每个字符的两边都插入一个特殊的符号，将所有可能的奇数或偶数长度的回文子串都转换成了奇数长度。
   比如 abba 变成 #a#b#b#a#， aba变成 #a#b#a#，这样就不用考虑奇数偶数的问题了。 

2、为了进一步减少编码的复杂度，可以在字符串的开始加入另一个特殊字符，这样就不用特殊处理越界问题，比如$#a#b#a#（其实最前面特殊字符的选择可以任意，不会影响计算结果） 

3、用一个数组 P[i] 来记录以字符S[i]为中心的最长回文子串向左或向右扩张的长度（包括S[i]），P[i]-1则是是原字符串中最长回文串的总长度 

4、增加两个辅助变量id和mx，其中id表示最大回文子串中心的位置，mx则为id+P[id]，也就是最大回文子串的边界。得到一个很重要的结论：
   如果mx > i，那么P[i] >= Min(P[2 * id - i], mx - i) 
   对于 mx <= i 的情况，因为无法对 P[i]做更多的假设，只能让P[i] = 1，然后再去匹配	
*/
#include <iostream>
#include <string>
using namespace std;

//得到小的数 
int minNum(int a,int b)
{
	if(a>b)
		return b;
	return a;
}

//处理字符串 
string handleString(string &s){
	int i;
	string sTemp="$#";//初试字符串为$# 
	for(i=0;i<s.length();++i){//遍历每个字符 
		sTemp+=s[i];
		sTemp+="#";//每次补充一个#字符 
	}
	return sTemp;
} 
//求最长回文串长度 
int longestPalindrome(string &s)
{
	//cout<<s<<endl;
	int p[100],mx=0,id=0,i,max=0;
	for(i=1;i<s.length();++i){
		p[i]=mx>i ? minNum(p[2*id-i],mx-i) : 1;//因为结论P[i] >= Min(P[2 * id - i], mx - i)，初试取等号，后续继续扩充判断，对于 mx <= i 的情况，因为无法对 P[i]做更多的假设，只能让P[i] = 1，然后再去匹配 
		while(s[i+p[i]]==s[i-p[i]]){//继续扩充判断 
			p[i]++;
		}
		if(i+p[i]>mx){//如果扩充后边界大于mx，更新边界，更新id 
			mx=i+p[i];
			id=i;
		}
	}
	for(i=1;i<s.length();i++){//遍历p[]数组，找到最大的值 
		if(max<p[i])
			max=p[i];
	}
	return max-1;
}

int main()
{
	//输入 
	string s;
	cout<<"请输入字符串："<<endl;
	cin>>s;
	//处理字符串
	string s0=handleString(s); 
	//输出结果 
	cout<<"结果："<<longestPalindrome(s0)<<endl;
	return 0;
} 
