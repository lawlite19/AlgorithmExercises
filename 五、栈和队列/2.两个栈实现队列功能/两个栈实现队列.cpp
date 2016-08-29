/*
问题：使用两个队列实现队列的add（入队）,poll（出队）,peek（获取队头元素）功能 
 
1、将数据放入一个栈stackPush，再将栈中元素依次弹出到另一个栈中stackPop 
	5	1
	4	2
	3	3
	2	4
	1	5
2、需要注意两点
	（1）stackPush一次要全部倒出 
	（2）若stackPop不为空，stackPush不能倒出 
*/ 
#include <iostream>
#include <stack>
using namespace std;

class TwoStackQueue//自定义一个类，实现以上功能 
{
	private:
		stack<int> stackPush;//压入栈 
		stack<int> stackPop;//弹出栈 
	public:
		void add(int number);
		int poll();
		int peek();
}; 
//入队 
void TwoStackQueue::add(int number)
{
	stackPush.push(number);//压入栈直接入栈 
}
//出队 
int TwoStackQueue::poll()
{
	if(stackPush.empty() && stackPop.empty()){//若两个栈都为空，则队列为空 
		return -1;
	}
	else if(stackPop.empty()){//若是弹出栈为空 
		while(!stackPush.empty()){//将压入栈全部压入 
			stackPop.push(stackPush.top());
			stackPush.pop();//pop操作只是弹出，并不返回元素，所以分开写，与java中不同 
		}	
	}
	
	int value=stackPop.top();//获取栈顶（即为队头） 
	stackPop.pop();//出栈 
	return value;
}
//获取队头元素 
int TwoStackQueue::peek()
{
	if(stackPush.empty() && stackPop.empty()){//若两个栈都为空，则队列为空
		return -1;
	}
	else if(stackPop.empty()){//同上 
		while(!stackPush.empty()){
			stackPop.push(stackPush.top());
			stackPush.pop();
		}	
	}
	
	return stackPop.top();//获取弹出栈栈顶（即为队头元素） 
}

int main()
{
	//进队 
	TwoStackQueue queue;
	int data,n=0;
	cout<<"请输入入队元素（以-1结尾）："<<endl;
	while(cin>>data && data!=-1){
		queue.add(data);
		++n; 
	} 
	
	//输出
	cout<<"输出结果："<<endl;
	for(int i=0;i<n;++i){
		cout<<"出队"<<(i+1)<<"次,弹出队头元素为："<<queue.poll();
		if(queue.peek()!=-1)
			cout<<"，此时队头元素为："<<queue.peek()<<endl; 
		else
			cout<<"，此时队为空"<<endl;
	} 
	
	return 0;
}
