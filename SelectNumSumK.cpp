/*************************************************************************
	> File Name: SelectNumSumK.cpp
	> Author: YeGuoSheng
	> Description:Select a few Numbers in a number of positive integers, satisfy and is k, 
	and find the group that selects the least elements
	> Created Time: 2019-04-15  22:24:03
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

#define  MAX 20
int n ;
int w[MAX];
int x[MAX];
int tw;
int rw;
int k;
int number = 0;
int minnumber = 0x7f7f7f;
int op[MAX];
int minsol[MAX] = {0};

void dfs(int tw,int rw,int i,int number,int op[])
{
	if(i > n)
	{
		int j = 0;
		if(tw == k)
		{
			 if(number < minnumber)
			 {
				minnumber = number;//update minarr
				for(int i = 1 ;i <= n;i++)
				{
					if(x[i] == 1)
					{	
						minsol[j++] = w[i];
					}	
				}
			 }
		}
	}
	else
	{
		op[i]  = 1;
		if(tw + w[i] <= k)
		{
			x[i]  = 1;
			dfs(tw + w[i], rw - w[i], i+1,number + 1,op);
		}
		op[i] = 0;
		if(tw + rw > k)
		{
			x[i] = 0;
			dfs(tw,rw - w[i],i+1,number,op);
		}
	}
}

void Disp()
{
	for(int i = 0;i<minnumber;i++)
	{
		cout<<minsol[i]<<" ";
	}
}

int main()
{
	memset(op,0,sizeof(op));
	memset(w,0,sizeof(w));
	memset(x,0,sizeof(x));
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>w[i];
		rw +=w[i];
	}
	cin>>k;
	dfs(0,rw,1,0,op);
	Disp();
    return 0;
}
