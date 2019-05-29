/*************************************************************************
	> File Name: nqueen.cpp
	> Author: YeGuoSheng
	> Description:  
	> Created Time: 2019年04月11日 星期四 21时11分45秒
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

#define MAXN 20
int q[MAXN];
int n;
int counter = 0;

void Disp()
{
	cout<<"Solution :"<<++counter<<endl;
	for(int i = 1;i <= n;i++)
	{
		cout<<" ("<<i<<","<<q[i]<<")";
	}
	cout<<endl;
}

bool IsOk(int i)
{
	int j = 1;
	if(i == 1)return true;
	while(j < i)
	{
		if(q[i] == q[j] ||  (abs(q[j] - q[i]) == abs(i - j)))
		{
			return false;
		}
		j++;
	}
	return true;
}

void dfs()
{
	int i = 1;
	q[i]  = 0;
	while(i >= 1)
	{
		q[i] ++;
		while(q[i] <= n && !IsOk(i))
		{
			q[i] ++;
		}
		if(q[i] <= n)
		{
			if(i == n)
			{
				Disp();
			}
			else
			{
				i++;
				q[i] = 0;
			}
		}
		else
		{
			i--;
		}
		
	}
}


int main()
{
	cin>>n;
	dfs();
    return 0;
}
