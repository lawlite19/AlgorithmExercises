/*
问题：判断A字符串是否包含B字符串（A：12,B：111同样表示包含） 

（可以使用Hashtable，将A中的字符放在Hashtable中，然后遍历B即可。） 
这里使用一个整数hash代替Hashtable, 利用位运算
1、初试hash为0
2、遍历A，计算每个字符到具体一个字符的距离（这里我用的a），然后将1“左移“这个距离，然后hash按为“或 ”运算（一个1则为1）这个数 ，
	（重复的字母这样得到的那个位置也是1），这样就相当于在二进制中用1代表存在此字符 
3、遍历B，利用“与”运算（两个为1才为1），所以如果与运算为0，说明没有找到这个字符 
eg:abc==>二进制：111==>7，B中每个字符利用相同的移动规则得到数和7进行“与”运算，为0说明此位置没找到 
*/
#include <iostream>
#include <string> 
using namespace std;

bool stringContain(string &s1,string &s2)
{
	int hash=0,i;
	for(i=0;i<s1.length();++i)//遍历s1 
		hash |=(1<<(s1[i]-'a'));//将1<<左移某个距离，然后与hash按位|或运算 
	for(i=0;i<s2.length();++i)// 遍历s2 
		if((hash & (1<<(s2[i]-'a')))==0)//相同的规则将1<<左移某个距离，与得到的hash按位&与运算，如果为0说明没有找到 
			return false;
	return true;
}

int main()
{
	//输入 
	string s1,s2;
	cout<<"请输入一个字符串："<<endl;
	cin>>s1;
	cout<<"请输入另外一个字符串："<<endl;
	cin>>s2;
	//输出结果
	cout<<"结果："<<stringContain(s1,s2)<<endl; 
	return 0;
}
