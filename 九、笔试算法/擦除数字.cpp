/*
题目描述： 
- 如果 Steph 最初写在黑板上的数是 816，那么每次擦除前黑板上的数是816，81，8。最终计算器中的结果是 816 + 81 + 8 = 905。 
  - 假设给出一个数 S (1 <= S <= 10^18)，Steph 想知道能否找到一个数 x，当写在 x 在黑板上后，执行擦除过程后计算器中得到的结果是 S。 
  - 如果不能得到，输出 -1，如果能得到，输出最小的 x。
方法：
- 816为例，从右往左擦除数字，最后的一位8就是计算3次，一次类推 8*(100+1+1)+1*(10+1)+6*1=905
- 所以就是求111*X+11*Y+Z=S ，枚举X、Y、Z即可 

*/

#include <bits/stdc++.h>
using namespace std;
#define N 10000

// 如果输入(1,9)，则输出9
// 如果输入(2,9)，则输出99
// 如果输入(3,9)，则输出999
long count(int times, int num)
{
	long p = 1;
	long sum = 0;
	while(times--){
		sum += num*p; 
		p *= 10;
	}
	return sum;
}

long solution(long num)
{
	int len = 0;
	long temp = num;
	while(temp){
		len++;
		temp /= 10;
	}
	int res[len];
	
	//寻找0-9合适的数字 
	int i,j;
	for(i=len-1; i>=0; i--){  //循环多少次 
		long sum = 0;
		for(j=9;j>=0;j--){
			long tmp = count(i+1, j);
			if(sum+tmp<=num){
				sum += tmp;
				break;
			}
		}
		res[i] = j;
		num -= sum;
	}
	if(num != 0)
		return -1;
	
	//构造结果
	long p = 1;
	long result = 0;
	for(int i=0;i<len;i++){
		result += res[i] * p;
		p *= 10;
	} 
	return result;
}
 
int main()
{
	long num;
	while(cin>>num){
		cout<<solution(num)<<endl; 
	} 
	return 0;
}
