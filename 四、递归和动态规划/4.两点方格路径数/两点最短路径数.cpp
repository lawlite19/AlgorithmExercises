/**
 * problem：两点间最短路径数, 即只能向上或者向右走（对应(x1, y1)在（x0, y0）右上方情况）
 * solve1: 长m，宽n，则向上走有m步，向右走有n步，状态转移为：
 *      f(i,j)=f(i-1,j)+f(i,j-1)   if i,j>0
        f(i,j)=f(i,j-1)            if i=0
        f(i,j)=f(i-1,j)            if j=0
   solve2: 排列组合数为：C(m+n, m) = C(m+n, n)
 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/**
 * 递归求解
 * @param m
 * @param n
 * @return
 */
int shortestPathCntRecursive(int m, int n){
    if(m == 0 && n == 0)  //递归结束
        return 0;
    if(m ==0 || n == 0)   // 有一个为0，说明走到了边上，只有一步，一种情况
        return 1;
    return shortestPathCntRecursive(m-1, n) + shortestPathCntRecursive(m, n-1);
}

/**
 * 动态规划，暂存状态
 * @param m
 * @param n
 * @return
 */
int shortestPathCntDP(int m, int n){
    if(m==0 && n==0)
        return 0;
    if(m==0 || n==0)
        return 1;
    vector<vector<int> > dp(m+1, vector<int>(n+1));
    for(int i=0; i<=m; i++)
        dp[i][0] = 1;
    for(int j=0; j<=n; j++)
        dp[0][j] = 1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

/**
 * 利用公式来求
 * @param m
 * @param n
 * @return
 */
int shortestPathFormula(int m, int n){
    if(m==0 && n==0)
        return 0;
    if(m==0 || n==0)
        return 1;
    int res = 1;
    for(int i=m+n; i>max(m, n); --i)  // 阶乘（m+n）到 max(m,n)
        res *= i;
    for(int i=min(m, n); i>1; --i)    //除以阶乘 min(m, n) 到 1
        res /= i;
    return res;
}

int main(){
    int x0, y0, x1, y1;
    cin>>x0>>y0>>x1>>y1;
    cout<<"递归求解："<<shortestPathCntRecursive(abs(x0-x1), abs(y0-y1))<<endl;
    cout<<"动态规划："<<shortestPathCntDP(abs(x0-x1), abs(y0-y1))<<endl;
    cout<<"公式求解："<<shortestPathFormula(abs(x0-x1), abs(y0-y1))<<endl;
    return 0;
}
