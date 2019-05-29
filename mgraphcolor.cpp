/*************************************************************************
	> File Name: mgraphcolor.cpp
	> Author: YeGuoSheng
	> Description:  M graph coloring problem, given undirected graph G and m different colors,
	use these colors to give each point graph color,
I want two vertices of different colors for each edge,
	> Created Time: 2019-04-11 22:22:48
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
int point;
int edge;
int coloenum;
int arr[MAXN][MAXN] = {0};
int color[MAXN] ={0};
int counter = 0;

bool IsSame(int i)//Determines whether vertex I has the same color as its neighbors
{
	for(int j = 1;j <=point ;j++)
	{
		if(arr[i][j] == 1 && color[i] == color[j])
		{
			return false;
		}
	}
	return true;
}

void Disp()
{
	cout<<++counter<<" Solution :";
	for(int j = 1;j <= point;j++)
	{
		cout<<color[j]<<" ";
	} 
	cout<<endl;
}
void dfs(int i)
{
	if(i > point)
	{
		Disp();
	}
	else
	{
		for(int j = 1;j <=coloenum;j++)//Search for each color
		{
			color[i] = j;
			if(IsSame(i))
			{
				dfs(i + 1);
			}
			color[i] = 0;
		}
	}
}

int main()
{
	cin>>point;
	cin>>edge;
	cin>>coloenum;
	int x;
	int y;
	for(int i = 1;i <= edge;i++)
	{
		cin>>x>>y;
		arr[x][y] = 1;
		arr[y][x] = 1;

	}
	dfs(1);
	if(counter > 0)
	{
		cout<<counter<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
	
    return 0;
}
