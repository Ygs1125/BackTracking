/*************************************************************************
	> File Name: complexshipload.cpp
	> Author: YeGuoSheng
	> Description:  Complicated loading problem. The two ships can respectively carry c1 and c2. 
	The weight of container I is wi, and w1+w2+... Wn < = c1 + c2
Find out if there is a loading scheme to load all these containers onto the ship
	> Created Time: 2019-04-11  20:39:37
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
int c1,c2;
int op[MAX]= {0};
int x[MAX] = {0};
int n;
int w[MAX] = {0};
int tw;
int rw;
int c1maxw = 0;

void dfs(int tw,int rw,int op[],int i)
{
	if(i > n)
	{
		if(tw <= c1 && tw > c1maxw)
		{
			c1maxw = tw;
			for(int j = 1;j<= n; j++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		op[i] = 1;
		if(tw + w[i] <= c1)
		{
			dfs(tw + w[i],rw - w[i],op,i +1 );
		}
		op[i] = 0;
		if(tw + rw > c1)
		{
			dfs(tw,rw - w[i],op, i + 1);
		}
	}
	
}

void Disp()
{
	for(int i = 1;i <= n;i ++)
	{
		if(x[i] == 1)
		{
			cout<<"Box "<<i<<" on the ship 1"<<endl;
		}
		else
		{
			cout<<"Box "<<i<<" on the ship 2"<<endl;
		}
	}
}

bool Judge()
{
	int  sum = 0 ;
	for(int i = 1;i<= n;i ++ )
	{
		if(x[i] == 0)
		{
			sum += w[i];
		}
	}
	if(sum < c2)return true;
	else return false;	
}

int main()
{
	cin>>c1>>c2;
	cin>>n;
	for(int i = 1; i <= n;i++)
	{
		cin>>w[i];
		rw += w[i];
	}
	dfs(0,rw,op,1);
	if(Judge())
	{
		Disp();
	}
	else
	{
		cout<<"No methods"<<endl;
	}
	
    return 0;
}
