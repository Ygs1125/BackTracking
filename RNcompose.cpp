/*************************************************************************
	> File Name: R/Ncompose.cpp
	> Author: YeGuoSheng
	> Description:  
	> Created Time: 2019年04月16日 星期二 20时46分16秒
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
int arr[MAX] = {0};
int vis[MAX] ={0};
int n;
int m;

void dfs(int i)
{
	if(i > m)
	{
		for(int i =1 ;i <= m ;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		/* code */
		for(int j =1;j <=n;j++)
		{
			if(vis[j] == 0 )
			{
				arr[i]= j;
				vis[j]  = 1;
				dfs(i +1);
				arr[i] = 0;
				vis[j] = 0;
			}
		}
	}
	
}

int main()
{
	cin>>n;
	cin>>m;
	dfs(1);
	return 0;
}
