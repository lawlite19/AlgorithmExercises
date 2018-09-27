/**
    问题描述：字符串的最短前缀表示
    solution: 使用前缀树，n表示字符串出现的次数，所以最短前缀就是出现次数为1的下一个位置
  **/


#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ALPHABET_SIZE 26

struct TreeNode{
    int n;
    struct TreeNode* children[ALPHABET_SIZE];
};


TreeNode* initNode(){
    TreeNode* root = new TreeNode();
    root->n = 0;
    for(int i=0; i<ALPHABET_SIZE; i++){
       root->children[i] = NULL;
    }
    return root;
}

void insert(TreeNode* root, string str){
    TreeNode* node = root;
    for(int i=0; i<str.size(); i++){
        int index = str[i] - 'a';
        if(node->children[index]==NULL)
            node->children[index] = initNode();
        node->n = node->n + 1;
        node = node->children[index];
    }
}

vector<string> shortestPrefix(vector<string> strs){
    TreeNode* root = initNode();

    for(int i=0; i<strs.size(); i++){
        insert(root, strs[i]);
    }    

    vector<string> res;
    TreeNode* node;
    int i, j;
    for(i=0; i<strs.size(); i++){
        node = root;
        for(j=0; j< strs[i].size(); j++){
            int index = strs[i][j] - 'a';
            if(node->children[index]->n<=1)
                break;
            node = node->children[index];
        }
        res.push_back(strs[i].substr(0, j+1));
    }
    return res;
} 


int main(){
    vector<string> strs;
    strs.push_back("bytearray");
    strs.push_back("testapp");
    strs.push_back("testbpp");
    strs.push_back("iecsa");
    strs.push_back("iecca");
    vector<string> res = shortestPrefix(strs);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
