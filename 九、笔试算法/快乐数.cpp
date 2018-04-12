/*
快乐数： 
Example
19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
- 有一个坑就是出现4的话会产生循环，可以使用一个set判断是否曾经的数出现过，若是出现过直接跳出 
*/ 

#include <bits/stdc++.h>
using namespace std;



string isHappyNumber1(long num)
{
	while(num != 1){
		set<long> s; 
		int t = 0;
		while(num){
			t += (num%10)*(num%10);
			num /= 10;
		}
		num = t;
		if(s.count(num))  //如果存在 
			break;
		else
			s.insert(num);
	}
	if(num==1)
		return "true";
	return "false";
}

string isHappyNumber(long num)
{
	while(num != 1 && num != 4){
		int t = 0;
		while(num){
			t += (num%10)*(num%10);
			num /= 10;
		}
		num = t;
	}
	if(num==1)
		return "true";
	return "false";
}

int main()
{
	long num;
	while(cin>>num){
		cout<<isHappyNumber1(num)<<endl;
		cout<<isHappyNumber(num)<<endl;
	}
	return 0;
}
