/**
 * problem: 求二叉树的最大和最小深度
 * solution1: 深度遍历
 * solution2: 广度遍历
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
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
 * 最大深度bfs，一直往下走，退回到上一级时选择最大的深度即可
 * @param root
 * @return
 */
int maxDepth_dfs(TreeNode* root) {
    if(root == NULL)
        return 0;
    int left = maxDepth_dfs(root->left) + 1;
    int right = maxDepth_dfs(root->right) + 1;
    return max(left, right);
}

/**
 * 最大深度bfs, 记录层数
 * @param root
 * @return
 */
int maxDepth_bfs(TreeNode* root){
    if(root == NULL)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int low = 0;
        int high = q.size();
        while(low<high){
            low++;
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
        cnt++;
    }
    return cnt;
}

/**
 * 最小深度，一直往下走，如果当前节点left为空，为right的长度（因为并非为叶子节点），
 *        如果左右子树都不为空，返回最小的
 * @param root
 * @return
 */
int minDepth_dfs(TreeNode *root){
    if(root == NULL)
        return 0;
    int left = minDepth_dfs(root->left) + 1;
    int right = minDepth_dfs(root->right) + 1;
    if(root->left == NULL)
        return right;
    else if(root->right == NULL)
        return left;
    else
        return min(left, right);
}

/**
 * 最小深度bfs, 记录层数，若左右子树都为空，返回当前层数
 * @param root
 * @return
 */
int minDepth_bfs(TreeNode* root){
    if(root == NULL)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int low = 0;
        int high = q.size();
        while(low<high){
            low++;
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
            if(node->left == NULL && node->right == NULL)
                return cnt+1;
        }
        cnt++;
    }
    return cnt;
}

int main(){
    vector<int> a = {1,2,4,0,6,0,0,5,7,0,0,0,3,0,0};
    int pos = -1;
    TreeNode* root = createBinaryTree(a, pos);
    cout<<"最大深度dfs为： "<<maxDepth_dfs(root)<<endl;
    cout<<"最大深度bfs为： "<<maxDepth_bfs(root)<<endl;
    cout<<"最小深度dfs为： "<<minDepth_dfs(root)<<endl;
    cout<<"最大深度dfs为： "<<minDepth_bfs(root)<<endl;

    return 0;
}