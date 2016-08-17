/*
首先将字符串进行快速排序，然后进行遍历判断,因为有序，遍历时A就不需要每次从头开始遍历了 
时间复杂度为：O（mlogm）+O（nlogn）+O（m+n） 
*/ 
#include <iostream>
#include <string> 
using namespace std;

//快速排序 
void quickSort(string &s,int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	char key=s[low];
	while(i<j){
		while(i<j && s[j]>=key)
			--j;
		s[i]=s[j];
		while(i<j && s[i]<=key)
			++i;
		s[j]=s[i];
	}
	s[i]=key;
	quickSort(s,low,i-1);
	quickSort(s,i+1,high);
} 
//判断是否包含 
bool stringContain(string &s1,string &s2)
{
	quickSort(s1,0,s1.length()-1);
	quickSort(s2,0,s2.length()-1);//快排 
	//cout<<s1<<"   "<<s2<<endl;
	int i,j;
	for(i=0,j=0;j<s2.length();++j){//遍历s2字符串 
		while(i<s1.length() && s1[i]<s2[j])//遍历s1，如果没有匹配s1位置就++ 
			++i;
		if(i>=s1.length() || s1[i]>s2[j])//如果没有找到（两种情况：一种是i的位置越界，二是当前位置字符大于s1当前位置的值）就返回false
			return false;
	}
	return true;
}

int main()
{
	//输入 
	string s1,s2;
	cout<<"请输入字符串a:"<<endl;
	cin>>s1;
	cout<<"请输入字符串b:"<<endl;
	cin>>s2;
	//输出结果 
	cout<<"结果："<<stringContain(s1,s2)<<endl; 
	return 0;
}
