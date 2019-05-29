/*************************************************************************
	> File Name: SolveEquation.cpp
	> Author: YeGuoSheng
	> Description:  Write a program to find a, b, c, d that satisfies the ab - CD - e = 1 equation,
	where all the variables are evaluated
It's 1 to 5 and it's not the same
	> Created Time: 2019-04-23  06:34:04
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
int arr[6] = {0};
int vis[6] = {0};

void Disp()
{
	for(int i = 1 ;i <=5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void dfs(int t)
{
	if(t > 5)
	{
		if(  arr[1] * arr[2] - arr[3] * arr[4] - arr[5] == 1)
		{
			Disp();
		}
		
	}
	else
	{
		for(int i = 1;i <= 5 ;i++)
		{
			if(vis[i] == 0)
			{
				arr[t] = i;
				vis[i] = 1;
				dfs(t + 1);
				vis[i] = 0;
			}
		}
	}
	return;
}


int main()
{
	dfs(1);
    return 0;
}
