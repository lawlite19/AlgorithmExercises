#include <stdio.h>
#include <map>
#include <list>
/*
问题：求一个数组中次数出现大于N/k的数

思路：与上题中次数出现N/2的问题类似，只是需要寻找k-1个候选
	1、遍历数组，若是a[i]与候选中元素相同，则对应的map中的value++
	2、若是不相同，判断候选是否满了（k-1个），若是没满，将新的a[i]作为候选
	3、若是满了，说明当前数是第K个数，把每个候选中key对应的value-1，同时若是
		value-1之后为0，需要删除map中对应key的空间
	4、上述就可以选中候选元素，然后遍历把每个候选出现的真正次数统计到map中判断 
	 
*/
#include <iostream>
using namespace std;

//map中每个key对应的value减一，同时若是value为0，则删除这个key对应的空间 
void allCandsMinusOne(map<int,int> &cands)//c++中的&引用，改变原始值 
{
	list<int> removeList;//记录value-1为0的集合的key，需要在候选map中删除key（删除key就是删除这个空间） 
	
	map<int,int>::iterator iter; 
 	for(iter = cands.begin(); iter != cands.end(); iter++){//遍历 
 		int key=iter->first;//得到key 
 		int value=iter->second;//得到value 
 		if(value==1)//如果value=1，则将其放入待删除list中 
 			removeList.push_back(key);
 		cands[key]=value-1;//对应value-1 
	}
	
	list<int>::iterator it;
	for(it=removeList.begin();it!=removeList.end();++it){//遍历删除即可 
		cands.erase(*it);
	}
}

//得到候选元素后统计每个候选出现的次数 
map<int,int> getReals(int *a,map<int,int> cands,int len)
{
	map<int,int> reals;
	for(int i=0;i<len;++i){		//遍历数组 
		int curNum=a[i];
		
		map<int,int>::iterator iter1;
		iter1 = cands.find(curNum); 
		if(iter1 != cands.end()){//在候选集合中找，若是找到，在最后的real集合中找 
			map<int,int>::iterator iter2;
			iter2=reals.find(curNum);
			if(iter2 != reals.end())//如果找到，对应位置+1 
				reals[curNum]=reals[curNum]+1;
			else
				reals[curNum]=1;	//否则令对应位置为1 
		}
	}
	return reals;
}

//打印map中的key和value，调试查看用 
void print(map<int,int> cands)
{
	map<int,int>::iterator iter; 
 	for(iter = cands.begin(); iter != cands.end(); iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

 
void KMajority(int *a,int k,int len)
{
	if(k<2 || len<1)//不满足情况返回 
		return;
	
	map<int,int> cands;
	for(int i=0;i<len;++i){		//遍历数组 
		map<int,int>::iterator iter; 
		iter = cands.find(a[i]);//候选中查找,若是找到，则对应key位置上value+1 
		if(iter != cands.end()){
			cands[a[i]]=cands[a[i]]+1;
		}
		else{
			if(cands.size()==k-1){//如果候选已满，调用所有元素对应的value-1 
				//cout<<"前："<<endl;
				//print(cands);
				allCandsMinusOne(cands);
				//cout<<"后："<<endl;
				//print(cands);
			}	
			else	//否则令新的元素key位置value为1 
				cands[a[i]]=1;
		}
	}
	//print(cands);	
	map<int,int> reals=getReals(a,cands,len);//得到每个候选元素出现次数的map 
	//print(reals);
	bool hasPrint=false;	//方便判断是否有N/k的元素标志 
	
	map<int,int>::iterator iter; 
 	for(iter = reals.begin(); iter != reals.end(); iter++){//遍历 
 		int key=iter->first;//first为key值 
 		if(reals[key]>len/k){//如果key对应的value>len/K，则为所求，打印输出 
 			hasPrint=true;
 			printf("%d ",key);
 		}
	}
	
	if(!hasPrint)//没有打印过，就是不存在 
		printf("没有找到");
}

int main()
{
	int a[]={1,1,2,3,1,2,3,2,3,1};
	int len=sizeof(a)/sizeof(int);
	int k=3;
	
	KMajority(a,k,len); 
	
	return 0;
} 
