/*************************************************************************
	> File Name: LuckyBag.cpp
	> Author: YeGuoSheng
	> Description: There are several balls in a bag, each request is marked with a number. 
You can repeat, for a bag
If and only if the sum of all the Numbers is greater than the sum of all the Numbers is lucky, 
you can remove 0 balls, but not all of them
Q: how many lucky bags can you get
	Input:
	3
	1 1 1
	Output:
	2
	> Created Time: 2019-05-08  22:55:47
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
/*
#define MAX 1001
int n;
int x[MAX] = {0};
int vis[MAX]  = {0} ;

int counter = 0;


void Disp(vector<int>path)
{
	cout<<"{";
	for(int i = 0;i <path.size();i ++)
	{
		cout<<path[i];
	}
	cout<<"}";
}

void dfs(int x[],int n,int i,vector<int>path)
{
	if(i >= n)
	{
		Disp(path);
		cout<<endl;
		int sum = 0;
		int product = 0;
		for(int i = 0 ;i < path.size();i++)
		{
			sum += path[i];
			product *= path[i];
		}
		if(sum > product)
		{
			cout<<"yes";
			counter ++;
		}
		
	}
	else
	{
		dfs(x,n,i + 1,path);
		path.push_back(x[i]);
		dfs(x,n,i + 1,path);
	}
}


int main()
{
	cin>>n;
	vector<int>path;
	for(int i = 0 ;i < n ;i++)
	{
		cin>>x[i];
	}
	dfs(x,n,0,path);
	cout<<counter<<endl;
    return 0;
}
*/
#define MAX 1005
int n;
int a[MAX];
int ans;
int times[MAX];//time[i]表示元素t的出现次数
int m;//times数组中元素的个数(不同号码的个数)

void Init()
{
	int t;
	m = 0;
	memset(times,0,sizeof(times));
	for(int i = 1;i <= n;i ++)
	{
		cin>>t;
		if(times[t]==0)
			a[++m] = t;
		times[t]++;
	}

}

void dfs(int i,  int sum,int mult)
{
	if(i > n)return ;
	dfs(i + 1,sum,mult);//not select a[i]
	for(int j = 1;j <= times[a[i]];j++)
	{
		sum += a[i];
		mult *= a[i];
		if(i != 1 && mult >= sum )break;
		if(sum > mult)ans++;
		dfs(i +1,sum,mult);
	}
}
int main()
{
	while( scanf("%d",&n)  != EOF)
	{
		Init();
		ans = 0;
		dfs(1,0,1);
		cout<<ans<<endl;
	}
	return 0;
}
