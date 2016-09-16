/*
问题： 给定一个 N*2 的二维数组，看作是一个个二元组，例如[[a1,b1],[a2,b2],[a3,b3]]，
		规定：一个如果想把二元组甲放在二元组乙上，甲中的 a 值必须大于乙中的 a 值，甲中的 b
		值必须大于乙中的 b 值。如果在二维数组中随意选择二元组，请问二元组最多可以往上摞
		几个？
		例如：[[5,4],[6,4],[6,7],[2,3]], 最大数量可以摞 3 个，[2,3] => [5,4] => [6,7]

O（NlogN）解法：（借助最长递增子序列的算法原型****） 
1、将二维数组按照第1个元素递增排列
2、在第一个元素相等的前提下，将二维数组按照第2个元素递减排列
3、遍历二维数组，按照第2个元素使用递增子序列的算法即可（因为第一个元素已经有序了） 

说明：在leetcode上通过
*/ 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//声明一个比较方法，stl自带排序可以根据制定的规则排序 
static bool judgeFirst(const pair<int,int> a, const pair<int,int> b) 
{
	if(a.first==b.first)//在X相等的条件下，按Y从大到小 
		return a.second>b.second;
	else return a.first<b.first;//否在按X从小到大 
}


int maxEnvelopes(vector<pair<int, int> >& envelopes) 
{
    int len=envelopes.size();
    if(len<1)
        return 0;
    sort(envelopes.begin(),envelopes.end(),judgeFirst);//调用stl的排序算法 
  	//最长递增子序列的O（NlogN）的解法即可 
	int end[len];
	end[0]=envelopes[0].second;
	int right=0;
	int l=0;
	int m=0;
	int r=0;
	for(int i=0;i<len;++i){
		l=0;
		r=right;
		while(l<=r){
			m=(l+r)/2;
			if(end[m]<envelopes[i].second)
				l=m+1;
			else
				r=m-1;
		}
		end[l]=envelopes[i].second;
		right=right>l?right:l;
	}
	return right+1;
}


int main()
{
	vector<pair<int, int> > list;
	list.push_back(make_pair<int,int>(1,3)); 
	list.push_back(make_pair<int,int>(3,5)); 
	list.push_back(make_pair<int,int>(6,7)); 
	list.push_back(make_pair<int,int>(6,8)); 
	list.push_back(make_pair<int,int>(8,4)); 
	list.push_back(make_pair<int,int>(9,5)); 
	printf("最多可以摞的个数：%d\n",maxEnvelopes(list));
	return 0;
}
