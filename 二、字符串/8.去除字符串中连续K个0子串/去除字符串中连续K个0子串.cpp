/*
问题：去除字符串中连续出现K个的0. eg:a00b  ==>  a  b

1、count用于统计连续0的个数，初值为0；start用于记录每次首次出现0的位置，初值为-1
2、遍历字符串，若str[i]=='0', start=start==-1 ? i : start,因为若start==-1,则之前没有出现0
	所以为当前位置i，否则start不变
3、若str[i]!='0'，判断count是否等于k，若是，则将0位置置为空格
4、我们每次当 str[i]!='0'时结算，所以若是以0结尾，需要最后判断一次 
*/
#include <iostream>
#include <string>
using namespace std;

string removeKZeros(string &str,int k)
{
	if(str.empty() || k<1)
		return str;
	
	int count=0;//统计每次0的个数 
	int start=-1;//每次串0开始的位置 
	
	for(int i=0;i<str.length();++i){//遍历字符串 
		if(str[i]=='0'){//若为0 
			++count;
			start = start == -1 ? i : start;//处理start的位置**，若是为-1,则start为i,否则不变，还是start 
		}
		else{//否则判断是否相等 
			if(count==k){
				while(count--)
					str[start++]=0;//将位置置为空格，0的ASCII为空格 
			}
			count=0;//重置 
			start=-1;
		}
	}
	if(count==k)//最后再判断一次 
		while(count--)
			str[start++]=0;
			
	return str;
}

int main()
{
	//输入 
	cout<<"请输入字符串："<<endl; 
	string str;
	cin>>str;
	cout<<"请输入K："<<endl;
	int k;
	cin>>k;
	
	//输出结果
	cout<<removeKZeros(str,k); 
	
	return 0;
}
