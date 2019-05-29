/*************************************************************************
	> File Name: MeetingArrange.cpp
	> Author: YeGuoSheng
	> Description:Solve the scheduling problem by entering n test cases, followed by p and k
Represents the start and end times, and outputs the maximum elapsed time for all activities
	Simple
	Input：
	4
	1 2
	3 5
	1 4
	4 5
	Output;
	4
	> Created Time: 2019-04-23  07:08:32
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

int n;
int lasttime = 0;

bool vis[100]  = {0};
int sum;
int maxsum;

int x[1000] = {0};
struct Action
{
	/* data */
	int b;
	int e;
}meet[100];


bool Cmp(Action x,Action y)
{
	if(x.b == y.b)
	{
		return x.e < y.e;
	}
	return x.b < y.b;
}

// void Disp()
// {
// 	for(int i  = 0 ; i < n;i++)
// 	{
// 		cout<<meet[i].mnum<<" "<<meet[i].b<<" "<<meet[i].e<<endl;
// 	}
// }

void dfs(int step)
{
	if(step > n)
	{
		if(sum > maxsum)
		{
			maxsum = sum;
		}

	}
	else
	{
		for(int j = step;j <= n; j++)//n meeting
		{
			int sum1 = sum;
			int laste = lasttime;
			if(meet[x[j]].b >= lasttime)
			{
				sum += meet[x[j]].e - meet[x[j]].b;
				lasttime = meet[x[j]].e;
			}
			swap(x[step],x[j]);
			dfs(step + 1);
			swap(x[step],x[j]);
			sum = sum1;
			lasttime = laste;

		}
	}
	
}


int main()
{
	cin>>n;
	for(int i = 1; i <= n;i++)
	{
		cin>>meet[i].b>>meet[i].e;
	}
	for(int j = 1;j <= n;j++)
	{
		x[j] = j;
	}
	sort(meet,meet+n,Cmp);
	dfs(1);
	cout<<maxsum<<endl;
    return 0;
}
