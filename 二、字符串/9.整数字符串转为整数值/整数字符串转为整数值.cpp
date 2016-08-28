/*
问题：将整数字符串转为整数值
	要求：（1）023 ==>返回0
		  （2）-0123==>返回0
		  （3）越界==>返回0
		  （4）有其他字符==>返回0
		   
需要在越界前判断出来数是否可以继续处理，如果越界就报错了。** 

1、判断字符串是否合法
2、统一将数当做负数处理，就不需要分情况了，因为负数最大绝对值比正数大1，最后根据posi返回，'0'-str[i]即为对应的负数了。 
3、bool型posi记录正负，result记录结果，minq=INT_MIN/10,minr=INT_MIN%10,这两个用于判断是否越界
	若是越界不需要继续遍历了。如何判断呢，如果当前result<minq（因为当负数处理的）或者res==minq 但是minr>当前处理的数字，相加后也肯定越界 
4、判断一下若是posi为true（正数）而result=INT_MIN，返回0 
5、最后判断若是posi为false，则返回result（因为当负数处理的），否则返回true 
*/
#include <iostream>
//#include <limits.h>
using namespace std;
#define INT_MIN (-2147483647 - 1)//宏定义，定义int的最小值（limits.h头文件中也是有定义的） 

//判断字符串是否合法 
bool isValide(string &str)
{
	if(str[0]!='-' && (str[0]<'0' || str[0]>'9'))//首位为其他字符 
		return false;
	
	if(str[0]=='-' && (str.length()==1 || str[1]=='0'))//首位为-,但是长度为1或第二位为0 
		return false;
	
	if(str[0]=='0' && str.length()>1)//首位为0且长度大于1 
		return false;
	
	for(int i=1;i<str.length();++i)//其余情况只能遍历判断了 
		if(str[i]<'0' || str[i]>'9')
			return false;
	
	return true; 
}

int convert(string &str)
{
	if(str.empty() || str=="")//为空，返回0 
		return 0;
		
	if(!isValide(str))//判断是否合法 
		return 0;
		
	bool posi=str[0]=='-' ? false : true;//posi记录正负，false为负 
	int minq=INT_MIN/10;//计算越界前位数的数 
	int minr=INT_MIN%10;//计算越界前位数的数最多还能加多少 
	int result=0;//存储结果 
	int current=0;//当前处理数 
	
	for(int i=posi ? 0 : 1;i<str.length();++i){//遍历，从非-位置开始遍历 
		current='0'-str[i];//得到当前数对应的负数 
		if((result<minq) || (result==minq && current<minr))//判断当前是否越界 
			return 0;
		result=result*10+current;//修改结果 
	}
	if(posi && result==INT_MIN)//判断是否可以转为正数 
		return false;
	
	return posi ? -result:result;//根据posi返回结果 
	
} 

int main()
{
	//输入
	cout<<"请输入字符串："<<endl;
	string str;
	cin>>str;
	
	//输出结果
	cout<<"结果为:"<<convert(str)<<endl; 
	
	return 0;
} 
