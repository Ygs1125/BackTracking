/*************************************************************************
	> File Name: 01bag.cpp
	> Author: YeGuoSheng
	> Description: Given n items, weight of w1,w2,w3... Wn, and the value 
	of each article is V1, v2, v3... Vn limits W to the total weight to 
	solve the optimal solution
	> Created Time: 2019-04-09  17:00:15
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

int n = 4;
int W = 6;
int w[] = {0,5,3,2,1};
int v[] = {0,4,4,3,1};
int x[MAX];
int maxv = 0;

void dfs(int i,int tw,int tv,int rw,int op[])
//Tw has added weight and TV has added value and rw considers the total weight of remaining items when item I	
{
	if(i > n)
	{
		if(tw == W && tv > maxv )
		{
			maxv = tv;
			for(int j = 1;j <=n ;j++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		if(tw + w[i] <= W)// if the item to be put in is larger than the total weight, cut it off directly
		{
			op[i] = 1;
			dfs(i +1,tw+ w[i],tv+v[i],rw - w[i],op);
		}
		op[i]  = 0;
		if(tw  + rw > W)
//Right pruning, if you do not put in the items, the previous has been put in plus after the total weight is not considered less than W directly cut do not consider
		{
			dfs(i +1,tw,tv,rw - w[i],op);
		}
	}
	
}

void Disp()
{
	int i;
	for(i = 1;i < n;i++)
	{
		if(x[i] == 1)
		{
			cout<<"  X["<<i<<"] ";
		} 
	}
	cout<<endl;
	cout<<"Max value is "<<maxv<<endl;
}

int main()
{
	int op[MAX];
	dfs(1,0,0,12,op);
	Disp();
    return 0;
}
