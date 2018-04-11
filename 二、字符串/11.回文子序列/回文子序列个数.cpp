/*
回文子序列的个数
- 对于任意字符串，如果头尾字符不相等，则字符串的回文子序列个数就等于去掉头的字符串的回文子序列个数+去掉尾的字符串的回文子序列个数-去掉头尾的字符串的回文子序列个数；
- 如果头尾字符相等，则字符串的回文子序列个数就等于去掉头的字符串的回文子序列个数+去掉尾的字符串的回文子序列个数+1。
- 用dp[i][j]表示第i到第j个字符间的最长回文子序列的长度（i<=j），则状态转移方程为：
  - dp[i][j]=dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] ， if（s[i]！=s[j]）
  - dp[i][j]=dp[i+1][j] + dp[i][j-1] +1 ， if （s[i]==s[j]） 
*/

#include <bits/stdc++.h>
using namespace std;
#define N 59


void coutDP(vector<vector<int> > dp, int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}


//方法一：记忆化搜索dp
int dfs(string s, vector<vector<int> > dp, int left, int right)
{
	if(left>right)
		return 0;
	if(left==right){
		dp[left][right] = 1;
		return dp[left][right];
	}
	if(dp[left][right]!=0){
		return dp[left][right];
	}
	dp[left][right] = dfs(s,dp,left+1,right)+dfs(s,dp,left,right-1)-dfs(s,dp,left+1,right-1);
	if(s[left]==s[right]){
		dp[left][right] += dfs(s,dp,left+1,right-1)+1;
	}
	return dp[left][right];
}


// 方法二：直接dp 
int allPalindrome(string s)
{
	int len = s.length();
	vector<vector<int> > dp(N, vector<int>(N));
	for(int j=0;j<len;j++){
		dp[j][j] = 1;
		for(int i=j-1; i>=0; i--){
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if(s[i]==s[j])
				dp[i][j] += dp[i+1][j-1]+1;
		}
	}
	//coutDP(dp, len);
	return dp[0][len-1];
} 


int main()
{
	string s;
	vector<vector<int> > dp(N, vector<int>(N)); 
	while(cin>>s){
		cout<<allPalindrome(s)<<endl; 
		cout<<dfs(s,dp,0,s.length()-1)<<endl;
	}
	return 0; 
} 
