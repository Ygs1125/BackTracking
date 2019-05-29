/*************************************************************************
	> File Name: minweight.cpp
	> Author: YeGuoSheng
	> Description:  min weight question
	Simole 
	Input：
	3 3 7
	1 2 3
	3 2 1
	2 3 2
	1 2 3
	5 4 2
	2 1 2
	Output:
	1 2 3
	5
	> Created Time: 2019-05-05  04:20:51
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
#define MAX 102
int x[MAX];
int bestx[MAX];
int cw = 0;
int cc = 0;
int bestw = 99999;
int n;
int m;
int cost;
int w[MAX][MAX];
int c[MAX][MAX];

bool find(int i,int j)
{
	for(int k = 1;k <i;k++)
	{
		if(x[k] == j)
		{
			return true;
		}
	}
	return false;
}

void dfs(int i)
{
	int j;
	if(i > n)
	{
		if(cw < bestw)
		{
			bestw = cw;
			for(int j = 1;j <= n; j++)
			{
				bestx[j] = x[j];
			}
		}
	}
	else
	{
		for(int j = 1;j <= m; j++)
		{
			if(find(i,j))
			{
				continue;
			}
			if(cc + c[i][j] <= cost &&  cw + w[i][j] < bestw)
			{
				x[i]  = j;
				cc += c[i][j];
				cw += w[i][j];
				dfs(i+1);
				cc -= c[i][j];
				cw -= w[i][j];
			}
		}
	}
	
}


int main()
{
	cin>>n>>m>>cost;
	for(int i= 1;i <=n;i++)
	{
		for(int j = 1; j<=m ; j++)
		{
			cin>>w[i][j];
		}
	}
	for(int i= 1;i <=n;i++)
	{
		for(int j = 1; j<=m ; j++)
		{
			cin>>c[i][j];
		}
	}
	dfs(1);
	for(int i = 1;i <= n ; i++)
	{
		cout<<bestx[i]<< " ";
	}
	cout<<bestw<<endl;;
	cout<<endl;
    return 0;
}
