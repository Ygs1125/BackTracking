/*************************************************************************
	> File Name: PartAllArray.cpp
	> Author: YeGuoSheng
	> Description:  Choose m elements from 1 to n and output their permutations
If n = 3, m = 2; The result is (1,2) (1,3) (2,1) (2,3) (3,1) (3,2).
	> Created Time: 2019-04-16  20:45:58
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
int m;
int w[20]  = {0};
int vis[20] = {0};

void dfs(int i)
{
	if(i > m)
	{
		for(int i =1;i<=m;i++)
		{
			cout<<w[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int j = 1;j<=n;j++)
		{
			if(vis[j] == 0)
			{
				w[i] = j;
				vis[j] = 1;
				dfs(i +1);
				w[i] = 0;
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
