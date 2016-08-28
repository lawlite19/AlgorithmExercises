/*
问题：设计一个每次可以得到栈中最小元素的栈
	要求：pop,push,getMin操作时间复杂度都是O(1),可以利用现有栈结构 

1、定义两个栈，一个栈用于保存栈中元素，另一个栈用于保存每一步最小值 
2、eg:
	3	-->	1 
	1	-->	1
	5	-->	3 
	4	-->	3
	3	-->	3

*/
#include <iostream>
#include <stack>
using namespace std;

class MyStack//自定义一个类，用于完成上面的操作
{
	private://两个栈为私有成员变量 
		stack<int> dataStack;//存储数据栈 
		stack<int> minStack;//存储当前最小值栈
	public://声明成员函数 
		void push(int number);
		int pop();
		int getMin();	
};
//压栈操作
void MyStack::push(int number)
{
	if(minStack.empty())//若minStack为空，则将第一个元素压入 
		minStack.push(number);
	else if(number<=this->getMin())//若是当前元素小于等于minStack最小值，则压入 
		minStack.push(number);
	else//否则压入minStack中的最小值 
		minStack.push(this->getMin());
		
	dataStack.push(number);//压入数据栈 
}
//弹栈操作
int MyStack::pop()
{
	if(dataStack.empty())
		return -1;
	
	minStack.pop();//minStack需要同步弹出 
	int value=dataStack.top();//得到数据栈栈顶 
	dataStack.pop();//弹出数据栈栈顶 
	return value;
}
//得到当前栈中最小值 
int MyStack::getMin()
{
	if(minStack.empty())
		return -1;

	return minStack.top();//获取栈顶元素 
}

int main()
{
		MyStack myStack;
	//压栈 
	int data,n=0;
	cout<<"请输入数字序列，会依次压入栈中（以-1结尾）:"<<endl; 
	while(cin>>data && data!=-1){
		myStack.push(data);//压栈 
		n++;
	} 
	
	//每次弹出一个元素，获取栈中的最小值 
	cout<<"每次获得的最小值："<<endl;
	for(int i=0;i<n;++i){
		cout<<myStack.getMin()<<" ";
		myStack.pop();
	} 	
	cout<<endl;
	
	return 0;
}
