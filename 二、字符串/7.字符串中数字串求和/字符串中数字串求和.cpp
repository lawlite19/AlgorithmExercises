/*
问题：给定字符串，求其中的数字串代表的数字之和
要求：（1）忽略小数点
	  （2）数字左侧出现字符‘-’，当出现奇数个时代表负数，偶数个代表正数
	  		eg:a-1bc--12  ===>   -1+12=11 

1、声明三个变量，result代表当前累加和，number代表当前数字，posi为bool型，判断当前数字正负 
2、遍历字符串，判断当前字符，若不是数字，结算，将number置为0，判断是否为'-',若不是还是true，
	判断前一个字符是否为'-'，若是改变posi，否则posi为false 
3、number的计算为 number=number*10+(posi ? current : -current)
4、我们每次是遇到不是数字的字符结算，若是以数字结尾则最后的会少计算，所以最后再加上 
*/
#include <iostream>
#include <string> 
using namespace std;

int calResult(string &str)
{
	if(str.empty())
		return 0;
	int result=0;//存储当前累加和 
	int number=0;//当前收集到的数字  
	bool posi=true;//判断正负 
	
	int current;//当前处理的字符对应的整型 
	
	for(int i=0;i<str.length();++i){//遍历字符串 
		current=str[i]-'0';//得到当前字符对应的整型值 
		if(current<0 || current>9){//若不是数字 
			result+=number;//先结算 
			number=0;//将number重置 
			if(str[i]=='-'){//1、判断是否为‘-’ 
				if(i-1>=0 && str[i-1]=='-')//3、判断前一个是否为'-' 
					posi=!posi;//若是，则取反 
				else
					posi=false;//4、否则为false 
			}
			else	//2、否则posi还是true 
				posi=true;
		}
		else
			number=number*10+(posi ? current : -current);//当前收集的数字 
	}
	result+=number;//最后计算一次，防止以数字结尾没有结算 
	
	return result;
}

int main()
{
	//输入 
	cout<<"请输入字符串："<<endl; 
	string str;
	cin>>str;
	
	//输出结果
	cout<<"计算结果为："<<calResult(str)<<endl; 
	return 0;
}
