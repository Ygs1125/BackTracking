/*************************************************************************
	> File Name: AllArray.cpp
	> Author: YeGuoSheng
	> Description: Let n elements a[] ={a0... The an}
It may contain repeating elements, solve for all the different permutations 
of these elements for example: a[] ={1,1,2}
(1,1,2)(1,2,1)(2,1,1)
	> Created Time: 2019-04-15  23:00:16
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

bool Ok(int a[],int i,int j)
{
	if(j > i)
	{
		for(int k = i ;k < j ;k++)
		{
			if(a[k] == a[j])
			{
				return false;
			}
		}
	}
	return true;
}

void dfs(int a[],int n,int i)
{
	if(i == n)
	{
		for(int j = 0;j < n;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	else
	{
		
		for(int j = i; j < n;j++)
		{
			if(Ok(a,i,j))
			{
				swap(a[i],a[j]);
				dfs(a,n,i+1);
				swap(a[i],a[j]);
			}
		}
	}
}

int main()
{
	int a[] ={1,2,1,2};
	int n = sizeof(a)  / sizeof(a[0]);
	for(int i = 0; i < n-1;i++)
	{
		cout<<a[i]<<" ";
	}	
	dfs(a,n,0);
    return 0;
}
