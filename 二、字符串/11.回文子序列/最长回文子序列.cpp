/*
最长回文子序列 
- 对于任意字符串，如果头尾字符相同，那么字符串的最长子序列等于去掉首尾的字符串的最长子序列加上首尾；
- 如果首尾字符不同，则最长子序列等于去掉头的字符串的最长子序列和去掉尾的字符串的最长子序列的较大者。
- 设字符串为str，长度为n，p[i][j]表示第i到第j个字符间的子序列的个数（i<=j），则：
  - 状态初始条件：dp[i][i]=1 （i=0：n-1） 
  - 状态转移方程：dp[i][j]=dp[i+1][j-1] + 2  if（str[i]==str[j]）
                  dp[i][j]=max(dp[i+1][j],dp[i][j-1])  if （str[i]!=str[j]）
*/


#include <bits/stdc++.h>
using namespace std;
#define N 100

//方法一：记忆搜索dp 
int dfs(string s, vector<vector<int> > dp, int left, int right)
{
	if(left>right)
		return 0;;
	if(left==right){
		dp[left][right] = 1;
		return 1;
	}
	dp[left][right] = max(dfs(s, dp, left+1, right), dfs(s, dp, left, right-1));
	if(s[left]==s[right]){
		dp[left][right] = dfs(s, dp, left+1, right-1) + 2;
	}
	return dp[left][right];
}

//方法二: 直接dp 
int longestPalindrom(string s)
{
	int len = s.length();
    vector<vector<int> > dp(N, vector<int>(N));
	for(int j=0;j<len;j++){
		dp[j][j]=1;
		for(int i=j-1;i>=0;i--){
			dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			if(s[i]==s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}
		}
	}	
	return dp[0][len-1];
}

int main()
{
	string s;
	vector<vector<int> > dp(N, vector<int>(N));
	while(cin>>s){
		cout<<dfs(s,dp, 0,s.length()-1)<<endl; 
		cout<<longestPalindrom(s)<<endl;
	}
	return 0;
} 
