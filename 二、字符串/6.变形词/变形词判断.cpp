/*
问题：两个字符串str1,str2, 若str1和str2出现的字符种类一样且每种字符出现的次数也一样，则为互为变形词
	eg:str1="123",str2="213" 

1、判断字符数是否相等，不等返回false
2、定义map数组，初试元素为0
3、遍历str1，对应字符位置map数组数值++
4、遍历str2，若是对应字符位置map位置数值<=0则返回false,否则对应字符位置map数组数值-- 
*/ 
#include <iostream>
#include <string>
using namespace std;

bool isdDeformation(string &str1,string &str2)
{
	if(str1.length()<1 || str2.length()<1 || str1.length()!=str2.length())
		return false;
		
	int map[256]={0},i;//map数组初始为0 
	
	for(i=0;i<str1.length();++i)//遍历str1，对应的字符处的map位置+1 
		map[str1[i]]++;
	
	for(i=0;i<str2.length();++i)//遍历str2，对应的字符处的map位置-1，若是map[i]<=0则返回false 
		if(map[str2[i]]--<=0)//这里map[i]--先是比较，比较后然后--(先使用，后--) 
			return false; 
		
	return true;
}

int main()
{
	//输入 
	string str1,str2;
	cout<<"请输入str1："<<endl;
	cin>>str1;
	cout<<"请输入str2："<<endl;
	cin>>str2;
	
	//结果
	cout<<"结果："<<isdDeformation(str1,str2)<<endl; 
	return 0;
} 
