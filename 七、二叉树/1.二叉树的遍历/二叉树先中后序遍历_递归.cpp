/*
问题：二叉树的先、中、后序递归遍历 
*/ 
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Node{//树的结构体定义 
	int value;
	Node *left;
	Node *right;
}BiNode,*BiTree; //*BiTree表示指向结构体的指针，BiNode表示这个结构体 

//先序遍历 
void preOrderRecursion(BiTree root){
	if(root){
		printf("%d ",root->value);
		preOrderRecursion(root->left);
		preOrderRecursion(root->right);
	}
}

//中序遍历
void inOrderRecursion(BiTree root)
{
	if(root){
		inOrderRecursion(root->left);
		printf("%d ",root->value);
		inOrderRecursion(root->right);
	}
}
//后续遍历
void posOrderRecursion(BiTree root)
{
	if(root){
		posOrderRecursion(root->left);
		posOrderRecursion(root->right);
		printf("%d ",root->value);
	}
} 

/*
		1
	  .	  .
	2		3
  .   .	   
4      5	     
 .    . 
  6  8 	
*/
int i=-1;
//先序递归建立树，建立的树如上图 
void createBiTree(BiTree *root)//*取出 
{
	int a[]={1,2,4,0,6,0,0,5,7,0,0,0,3,0,0};
	++i;
	if(a[i]==0)//为代表当前节点为空 
		*root=NULL;
	else{
		*root =(BiNode *)malloc(sizeof(BiNode)); //申请一个节点 
		if(!(*root))//没申请到就返回 
			return; 
		(*root)->value=a[i];//设置值 
		createBiTree(&(*root)->left);//递归 
		createBiTree(&(*root)->right);
	}
} 


int main()
{
	BiTree root;
	createBiTree(&root);//&取地址 
	printf("先序遍历结果：");
	preOrderRecursion(root);
	printf("\n中序遍历结果：");
	inOrderRecursion(root); 
	printf("\n后序遍历结果：");
	posOrderRecursion(root); 
	return 0;
} 
