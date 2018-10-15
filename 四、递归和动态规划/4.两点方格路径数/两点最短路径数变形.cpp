/**
 * problem: 问题同两点最短路径数，限制只能走y>=x的坐标
 * solve1: 递归
 * solve2: 公式，C(m+n, n) - C(m+n, n-1)
 */
#include <iostream>
using namespace std;

/**
 * 递归求解
 * @param m
 * @param n
 * @return
 */
int pathCntRecursive(int m ,int n){
    if(m==0 && n==0)
        return 0;
    if(m<n)        // 若是m<n，回退
        return 0;
    if(m==0 || n==0)
        return 1;
    return pathCntRecursive(m-1, n) + pathCntRecursive(m, n-1);
}

int pathCntFormula(int m, int n){
    if(m<n)
        return 0;
    int cnt1 = 1;
    int cnt2 = 1;
    for(int i=m+n; i>m; --i)
        cnt1 *= i;
    cnt2 = cnt1/(m+1);
    for(int i=n; i>1; --i)
        cnt1 /= i;
    for(int i=n-1; i>1; --i)
        cnt2 /= i;

    return cnt1-cnt2;
}

int main(){
    int x0, y0, x1, y1;
    cin>>x0>>y0>>x1>>y1;
    cout<<"递归求解："<<pathCntRecursive(abs(x0-x1), abs(y0-y1))<<endl;
    cout<<"公式求解："<<pathCntFormula(abs(x0-x1), abs(y0-y1))<<endl;
    return 0;
}