/*
问题：二叉树的先、中、后序非递归遍历

先序遍历非递归：
	1、借助栈，先将根入栈
	2、弹出栈顶并打印，然后将其右孩子**入栈（若有的话） 
	3、然后左孩子**入栈 （若有的话）
	4、然后回到2
中序遍历非递归： 
	1、借助栈，将整个树的左边界**一次入栈(root=root->left) 
	2、若root为空，则弹出栈顶node并打印，另root=node.right，然后重复1
	3、直到栈为空或root为空，结束
后序遍历（借助两个栈）***：
	1、栈s1，初始值为根
	2、弹出s1栈顶（root）放入栈s2，并将root左、右孩子依次*入栈s1（如果有的话）
	3、直到s1为空
	4、依次弹出s2的元素即为后序遍历结果 

后序遍历（借助一个栈）***：
	1、栈s1,变量root代表最近一次弹出并打印的阶段，变量c代表栈顶节点
	2、初始root为根，c=NULL
	3、若c的左孩子不为NULL，且h不等于c的左孩子也不等于c的右孩子，将c压入栈中
		（因为root代表最近一次弹出并打印的节点，如果root为c的左或右孩子，说明c的右子树打印完毕，
		  就不需要将c的左孩子要入栈中了，否则说明左子树没有处理过，将左孩子压入栈中） 
	4、若3不满足，并且c的右孩子不为NULL，且root不等于c的右孩子，则将c的右孩子压入栈
		（因为如果root为c的右孩子，代表右子树处理完毕，不需要将右孩子压入栈，否则就压入右孩子） 
	5、如果3、4都不满足，则将栈中弹出c并打印，然后令root=c 
		（说明左右子树都处理完毕，弹出栈顶并打印） 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef struct Node{//树的结构体定义 
	int value;
	Node *left;
	Node *right;
}BiNode,*BiTree; //*BiTree表示指向结构体的指针，BiNode表示这个结构体 

//先序遍历
void preOrderNotRecursion(BiTree root)
{
	if(root){//传入的树不为空 
		stack<BiTree> st;//定义一个栈，存的类型为BiTree类型 
		st.push(root);//初始值为根节点 
		
		while(!st.empty()){//遍历栈 
			root=st.top();//获取栈顶 
			st.pop();//弹出一个元素 
			printf("%d ",root->value);//打印弹出的元素 
			if(root->right)//若有右孩子，入栈 
				st.push(root->right);
			if(root->left)//然后再放左孩子 
				st.push(root->left);
		}
	}
} 

//中序遍历 
void inOrderNotRecursion(BiTree root)
{
	if(root){//若树不为空 
		stack<BiTree> st;//定义栈 
		while(!st.empty() || root){//如果栈不为空或者当前处理的节点不为空（因为刚开始栈就是空的） 
			if(root){//当前节点不为空 
				st.push(root);//入栈 
				root=root->left;//往左 
			}
			else{//左边为空了 
				root=st.top();//弹栈并打印 
				st.pop();
				printf("%d ",root->value);
				root=root->right;//指向右边，结束后又回到上面 
			}
				
		}	
	}
	
}
//后序遍历（借助两个栈）*** 
void posOrderNotRecursion1(BiTree root)
{
	if(root){
		stack<BiTree> s1;
		stack<BiTree> s2;
		s1.push(root);//初始值s1为根 
		while(!s1.empty()){//直到s1为空 
			root=s1.top();//弹出s1并付给root记录
			s1.pop();
			s2.push(root);//将弹出的放到s2 
			if(root->left)//左边孩子入栈s1 
				s1.push(root->left);
			if(root->right)//右边孩子入栈s2 
				s1.push(root->right);
		}
		while(!s2.empty()){//依次弹出栈s2 
			printf("%d ",s2.top()->value);
			s2.pop();
		}
	} 
}
//后序遍历（借助一个栈） 
void posOrderNotRecursion2(BiTree root)
{
	if(root){
		stack<BiTree> st;
		st.push(root);
		BiTree c=NULL;
		while(!st.empty()){
			c=st.top();
			if(c->left && root!=c->left && root!=c->right)
				st.push(c->left);
			else if(c->right!=NULL && root!=c->right)
				st.push(c->right);
			else{
				printf("%d ",st.top()->value);
				st.pop();
				root=c;
			}
		}
	} 
} 


/*
	      1
	  .	  .
	2	    3
     .    .	   
   4        5	     
     .    . 
      6  7 	
*/
int i=-1;
//先序递归建立树，建立的树如上图  
void createTree(BiTree *root)//*取出 
{
	int a[]={1,2,4,0,6,0,0,5,7,0,0,0,3,0,0};
	++i;
	if(a[i]==0)//为代表当前节点为空 
		(*root)=NULL;
	else{
		*root=(BiNode*)malloc(sizeof(BiNode));
		if(!(*root))//没申请到就返回 
			return;
		(*root)->value=a[i];//设置值 
		createTree(&(*root)->left);
		createTree(&(*root)->right);
	}
} 

int main()
{
	BiTree root;
	createTree(&root);//&取地址 
	
	printf("先序遍历结果：");
	preOrderNotRecursion(root);
	printf("\n中序遍历结果：");
	inOrderNotRecursion(root); 
	printf("\n后序遍历结果(借助两个栈)：");
	posOrderNotRecursion1(root); 
	printf("\n后序遍历结果(借助一个栈)：");
	posOrderNotRecursion2(root); 
	
	return 0; 
} 
