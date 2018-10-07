/**
 * problem: leetcode 127: https://leetcode.com/problems/word-ladder/description/
 * solution: 广度优先遍历， addNextWords负责找当前最近的单词（即只相差一个字符的单词），放入一个队列中
 *           直至队列为空，即全部查找完，当中若有等于endWord的，返回当前长度即可。
 * g++ -std=c++11 WordLadder.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
/**
 * 找与当前word差一个字符的word, 并将其放到队列中
 * @param word
 * @param wordSet
 * @param visited
 */
void addNextWords(string word, unordered_set<string>& wordSet, queue<string>& visited){
    for(int i=0; i<word.length(); ++i){
        char letter = word[i];
        for(int j=0; j<26; ++j){
            word[i] = 'a' + j;
            if(wordSet.find(word) != wordSet.end()){
                visited.push(word);
                wordSet.erase(word);
            }
        }
        word[i] = letter;
    }
}

/**
 * BFS, 遍历队列
 * @param beginWord
 * @param endWord
 * @param wordSet
 * @return
 */
int ladderLength(string beginWord, string endWord, unordered_set<string> &wordSet){
    queue<string> visited;
    addNextWords(beginWord, wordSet, visited);
    int distance = 2;
    while(!visited.empty()){
        for(int i=0; i<visited.size(); ++i){
            string word = visited.front();
            visited.pop();
            if(word == endWord){
                return distance;
            }
            addNextWords(word, wordSet, visited);
        }
        distance++;
    }
    return 0;
}

int getRes(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet;
    for(int i=0; i<wordList.size(); i++){  // vector 去重，使用unordered_set
        wordSet.insert(wordList[i]);
    }
    return ladderLength(beginWord, endWord, wordSet);
}


int main(){
    string beginWord = "hit", endWord = "cog";
    // ["hot","dot","dog","lot","log","cog"]
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout<<getRes(beginWord, endWord, wordList)<<endl;
    return 0;
}
