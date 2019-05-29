/*************************************************************************
	> File Name:allarray.cpp
	> Author: YeGuoSheng
	> Description:  {1,2,3}all array 
	> Created Time: 2019年04月09日 星期二 16时39分37秒
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
int n = 0;
int arr[20];
int vis[21] ={0};


void dfs(int step)
{
	if(step == n + 1)
	{
		for(int i = 1 ; i <= n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	for(int i = 1;i <=n;i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			arr[step] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
	return ;
}

int main()
{
	cin>>n;
	dfs(1);
    return 0;
}
