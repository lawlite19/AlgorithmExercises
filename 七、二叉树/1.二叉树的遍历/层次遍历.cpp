/**
 * 1. 层次遍历
 * 2. 层次遍历并输出行号
 * 编译： g++ -std=c++11 层次遍历.cpp
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
	      1
	  .	  .
	2	    3
     .    .
   4        5
     .    .
      6  7
*/
//先序递归建立树，建立的树如上图
TreeNode* createBinaryTree(vector<int>& a, int &i)
{
    TreeNode* node;
    ++i;
    if(i >= a.size())
        return NULL;
    else{
        if(a[i] == 0)//为代表当前节点为空
            node=NULL;
        else{
            node = new TreeNode(a[i]);
            node->left = createBinaryTree(a, i);//递归
            node->right = createBinaryTree(a, i);
        }
        return node;
    }
}
/**
 * 层次遍历，接错存储为vector
 * @param root
 */
vector<int> levelTravel(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> res;

    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        res.push_back(node->val);
        q.pop();
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    return res;
}

vector<vector<int> > levelWithRow(TreeNode* root){
    vector<vector<int> > res;
    vector<int> temp;
    queue<TreeNode*> q;
    if(root == NULL)
        return res;
    q.push(root);
    while(!q.empty()){
        int low = 0;
        int high = q.size();
        while(low<high){
            low++;
            TreeNode* node = q.front();
            temp.push_back(node->val);
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
            q.pop();
        }
        if(temp.size() > 0){
            res.push_back(temp);
            temp.clear();
        }
    }
    return res;
}

int main()
{
    vector<int> a = {1,2,4,0,6,0,0,5,7,0,0,0,3,0,0};
    int pos = -1;

    // 层次遍历结果
    cout<<"层次遍历结果："<<endl;
    TreeNode* root = createBinaryTree(a, pos);
    vector<int> res = levelTravel(root);
    for(int i=0; i<res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    // 层次遍历并输出行号结果

    cout<<"层次遍历结果和行号："<<endl;
    vector<vector<int> > res2 = levelWithRow(root);
    for(int i=0; i<res2.size(); i++){
        cout<<i<<": ";
        for(int j=0; j<res2[i].size(); j++){
            cout<<res2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}

