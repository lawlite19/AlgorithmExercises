/*
问题：输入n个整数，输出其中最小的k个 

一般解法：排序（O(nlogn)）、维护长度为k的数组（O(n*k)）或者维护一个k个元素的堆（O(n*logk)） 

这里采用BFPRT算法（O(n)）★★★：

 
*/
#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
} 

//插入排序 
void insertSort(int *a,int begin,int end)
{
	int i,j,t;
	for(i=begin+1;i<end;++i){
		if(a[i]<a[i-1]){
			t=a[i];
			for(j=i-1;j>=0 && a[j]>t;--j)
				a[j+1]=a[j];
			a[j+1]=t;
		}
	}
} 

//得到中位数 
int getMedian(int *a,int begin,int end)
{
	insertSort(a,begin,end);//排序 
	int sum=end+begin;
	int mid=(sum/2)+(sum%2);//中位数位置，因为当不满5个元素时，取下中位数，所以+sum%2 
	return a[mid];
}
int select(int *a,int begin,int end,int i);
//得到中位数的中位数 
int medianofMedians(int *a,int begin,int end)
{
	int num=end-begin+1;//总共数的个数 
	int offset=num%5==0 ? 0 : 1;//如果个数正好是5的倍数，偏移量为0，否则为1 
	int len=num/5+offset;//要求的中位数数组的长度 
	int mArr[len];
	
	for(int i=0;i<len;++i){//遍历数组 
		int beginI=begin+i*5;//每组的5个数开始位置 
		int endI=beginI+4;//计算的结束位置 
		mArr[i]=getMedian(a,beginI,end>endI?endI:end);//若结束位置<计算的结束位置，则为实际的结束位置 
	}
	
	return select(mArr,0,len-1,len/2);//调用select来求中位数的中位数，即求mArr中第len/2小的数 *** 
}

//a数组中找到第i小的数 
int select(int *a,int begin,int end,int i)
{
	if(begin==end)//递归出口1 
		return a[begin];
	
	int pivot=medianofMedians(a,begin,end);//得到中位数的中位数，即为划分元素 
	
	//下面一段代码相当于一次partition的过程，其中rangA，rangB主要求连续出现 pivot的位置区域，以此更加减少递归量 
	int small=begin-1;
	int cur=begin;
	int big=end+1;
	while(cur<big){
		if(a[cur]<pivot)
			swap(a+(++small),a+(cur++));
		else if(a[cur]>pivot)
			swap(a+cur,a+(--big));
		else
			cur++; 
	}
	int rangA=small+1;//连续出现pivot的左边界 
	int rangB=big-1;//连续出现pivot的右边界 
	//partition结束 
	
	if(i>=rangA && i<=rangB)//如果i（即为K）在位置区间，则a[i]为第k小的元素 
		return a[i];//递归出口2
	else if(i<rangA)//递归左边区域 
		return select(a,begin,rangA-1,i);
	else//递归右边区域（这里为什么还是i,而不是i-rangB,因为我们始终使用的是a数组，i位置还是第i小的元素 
		return select(a,rangB+1,end,i);
}

//获得第k小的元素 
int getMinKthByBFPRT(int *a,int k,int len)
{
	int copyA[len];
	for(int i=0;i<len;++i){
		copyA[i]=a[i];
	}
	 
	return select(copyA,0,len-1,k-1);//调用select，获得第K小的数 
} 

void getMinKNumsByRFPRT(int *a,int k,int len)
{
	if(k<1 || k>len)//不满足要求，返回 
		return;
		
	int minKth=getMinKthByBFPRT(a,k,len);//得到第k小的数 
	int res[k];
	int index=0;
	for(int i=0;i<len;++i)//遍历数组，发现比第k小的元素就放入res数组中（第k小的元素可能有多个） 
		if(a[i]<minKth)
			res[index++]=a[i];
	
	for(;index<k;++index)//因为第k小的元素可能有多个，上面若是没有找全k个，则其余位置都是minKth 
		res[index]=minKth;
	
	for(int i=0;i<k;i++)//输出结果 
		cout<<res[i]<<" ";
	cout<<endl; 
}

int main()
{
	//输入 
	int *a,n=0,data,k;
	cout<<"请输入数据（以-1结尾）："<<endl; 
	while(cin>>data && data!=-1){
		a[n++]=data;
	} 
	cout<<"请输入K值："<<endl;
	cin>>k;
	
	//输出结果
	cout<<"最小的"<<k<<"个数分别为：";
	getMinKNumsByRFPRT(a,k,n);
	
	return 0;
}
