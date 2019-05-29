/*************************************************************************
	> File Name: ShipWeight.cpp
	> Author: YeGuoSheng
	> Description:  Solve the simple loading problem.
	A batch of containers should be loaded onto a ship with a load of W, box number I (0<= I <=n-1).
The weight of is wi. Now we need to select several boxes from n containers and load them onto the ship,
so that their weight and weight are W.
	> Created Time: 2019-04-15  21:49:29
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
using namespace std;//5 2 6 4 3 ;W = 10

#define MAX 20 

int W;
int n;
int w[MAX];//each w
int rw;//last w
int cw;//current w

int op[MAX];
int x[MAX];
int counter   = 0;
void dfs(int cw,int rw,int op[],int i)
{
	if(i > n)
	{
		if(cw == W)
		{
			cout<<"counter:"<<++counter<<endl;
			for(int i = 1;i <= n;i++)
			{
				if(x[i] == 1)
				{
					cout<<"Select: "<<i<<" weight: "<<w[i]<<endl;
				}
			}
		}
	}
	else
	{
		op[i] = 1;
		if(cw + w[i] <= W)
		{
			x[i] = 1;
			dfs(cw + w[i],rw - w[i],op,i+1);
		}
		op[i]  = 0;
		if(cw + rw >= W)
		{
			x[i] = 0;
			dfs(cw,rw - w[i],op,i+1);
		}
	}

}

void DisoSolution()
{
	cout<<"counter:"<<++counter<<endl;
	for(int i = 1;i <= n;i++)
	{
		if(x[i] == 1)
		{
			cout<<"Select: "<<i<<" weight: "<<w[i]<<endl;
		}
	}
}

int main()
{
	memset(op,0,sizeof(op));
	memset(x,0,sizeof(x));
	rw = 0;
	cw = 0;
	cin>>n;
	for(int i = 1; i<=n ;i++)
	{
		cin>>w[i];
		rw += w[i];
	}
	cin>>W;
	dfs(0,rw,op,1);
    return 0;
}
