/*************************************************************************
	> File Name: shipload.cpp
	> Author: YeGuoSheng
	> Description: There are n containers to be loaded with ships of W weight,
wi weight of containers regardless of volume
To load the container onto the ship, the weight is required to be W, and the minimum number of containers is required
	> Created Time: 2019-04-09  17:18:10
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
int n;
int W;
int w[MAX] = {0};
int minnum = 100;
int x[MAX] = {0};
int op[MAX] = {0};
int rw = 0 ;
int maxw;

void dfs(int  num,int tw,int rw,int op[],int i)
{
	if(i > n)
	{
		if(tw == W && num < minnum )
		{
			maxw = tw;
			minnum = num;
			for(int j = 1 ;j <=n;j ++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		op[i] = 1;
		if( tw + w[i] <= W)
		{
			dfs(num + 1,tw + w[i],rw - w[i],op,i+1);
		}
		op[i] = 0;
		if(tw + rw > W)
		{
			dfs(num ,tw,rw-w[i],op,i+1);
		}
	}
}

void DispASolution()
{
	for(int i = 1;i <= n;i ++)
	{
		if(x[i] == 1)
		{
			cout<<"Select the "<<i<<" box,weight is "<<w[i]<<endl;
		}
	}
	cout<<"Total weight is "<<maxw<<endl;
}

int main()
{
	cin>>n;
	for(int j = 1; j <= n;j ++)
	{
		cin>>w[j];
		rw += w[j];
	}
	cin>>W;
	dfs(0,0,rw,op,1);
	DispASolution();
    return 0;
}
