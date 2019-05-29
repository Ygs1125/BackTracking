/*************************************************************************
	> File Name: sumofsubset.cpp
	> Author: YeGuoSheng
	> Description:  Given n sets of different positive integers w={w1,w2,w3... Wn} 
	and an integer W, find a subset of W Make and = = W
	> Created Time: 2019-04-11  20:54:47
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

#define MAX 20

int w[MAX] = {0};
int x[MAX] = {0};
int n = 0;
int W = 0;
int rw = 0;
int counter = 0;
void Disp()
{
	int i ;
	cout<<"Solution :"<<++counter<<endl;
	for(int i = 1;i <=n;i++)
	{
		if(x[i] == 1)
		{
			cout<<w[i]<<" ";
		}
	}
	cout<<endl;
}

void dfs(int tw,int rw,int X[],int i)
{
	if(i > n)
	{
		if(tw == W)
		{
			Disp();
		}
	}
	else
	{
		if(tw + w[i] <= W)
		{
			x[i] = 1;
			dfs(tw + w[i],rw - w[i],x,i+1);
		}
		if(tw + rw > W)
		{
			x[i] = 0;
			dfs(tw,rw - w[i],x,i+1);
		}
	}
	
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i ++)
	{
		cin>>w[i];
		rw += w[i];
	}
	cin>>W;
	dfs(0,rw,x,1);
    return 0;
}
