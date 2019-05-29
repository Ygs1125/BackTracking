/*************************************************************************
	> File Name: Hamiltonian.cpp
	> Author: YeGuoSheng
	> Description:  Given an undirected graph, specify a starting point and an ending point, 
	and pass through other vertices once
They're called Hamiltonian cycles. A closed Hamiltonian path can be described as a Hamiltonian Cycle.
An algorithm is designed to find all Hamiltonian circuits of undirected graphs
	> Created Time: 2019-04-17  07:21:25
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
#define MAXV 10
int n = 5;
int a[MAXV][MAXV] = {{0,1,1,1,0},{1,0,0,1,1},{1,0,0,0,1},{1,1,0,0,1},{0,1,1,1,0}}; 

int x[MAXV];
int counter;

void DispSolution()
{
	for(int i = 0; i <= n - 1;i++)
	{
		cout<<"("<<x[i]<<","<<x[i+1]<<")";
	}
	cout<<endl;
}

bool judge(int i)//judge the i node x[i] is value
{
	if(a[x[i-1]][x[i]] != 1)
	{
		return false;
	}
	for(int j = 0; j <= i -1;j++)
	{
		if(x[i] == x[j])
		{
			return false;
		}
	}
	return true;
}

void Hamiltonian(int v)//Find the Hamiltonian loop starting from vertex v
{
	x[0] = v;
	int i = 1;
	x[i]  = -1;
	while(i > 0)
	{
		x[i] ++ ;
		while( ! judge(i) && x[i] < n)
		{
			x[i]++;
		}
		if(x[i] < n)
		{
			if(i == n-1)
			{
				if(a[x[i]][v] == 1)
				{
					x[n] = v;
					cout<<"the " <<counter++<<" path "<<endl;
					DispSolution();
				}
			}
			else
			{
				i++;
				x[i] = -1;
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
	for(int v = 0;v < n;v++)
	{
		cout<<"from "<<v<<" the Hamiltonnian Cycle "<<endl;
		counter = 1;
		Hamiltonian(v);
	}
}
