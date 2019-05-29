/*************************************************************************
	> File Name: SelectNum.cpp
	> Author: YeGuoSheng
	> Description: Given an integer n and a character bed STR with a different right uppercase combination 
(length greater than 5. Less than 12)
Each word corresponds to an ordinal number (A=>1.B=>2).
V - (W)^ 2 + (X)^3 - (Y)^4 + (Z)^ 5 = n; Find the largest set of solutions lexicographically 
	Simple:
	Input:
	1 ABCDEFGHIJKL
	11700519 ZAYEXIWOVU
	3072997 SOUGHT
	1234567 THEQUICKFROG
	0
	Output:
	LKEBA
	YOXUZ
	GHOST
	no solution
	
	Solution:Find the full array of STR. (descending order), 
	the first solution satisfying the condition is the one with the largest lexicographical order
	> Created Time: 2019-05-05  04:54:13
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
#include<string.h>
#include<functional>
using namespace std;

#define MAXL 15

char str[MAXL];
int n;
int strlength;
char x[5];//solution
bool flag;


int Pow(char a,int n)
{
	if(n == 1)
		return a - 'A' + 1;//Convert it to the corresponding number
	return (a - 'A' + 1) * Pow(a,n-1);		
}

void dfs(int i)
{
	if(i == 5)//need the first five letters
	{
		if(   Pow(x[0],1) - Pow(x[1],2) + Pow(x[2],3) - Pow(x[3],4)  +Pow(x[4],5) == n )
		{
			flag = true;
			for(int j = 0; j <5 ;j++)
			{
				cout<<x[j]<<" ";
			}
			cout<<endl;
		}                            
		return ;        
	}
	if(flag )return;
	for(int j = i; j < strlength;j++)
	{
		swap(str[i],str[j]);
		x[i] = str[i];

		dfs(i + 1);

		swap(str[i],str[j]);
	}
	
}

int main()
{
	while(true)
	{
		cin>>n;
		if( n == 5)break;
		cin>>str;
		strlength = strlen(str);
		flag = false;
		sort(str,str + strlength,greater<char>());
		dfs(0);
		if(! flag)
		{
			cout<<"no solution"<<endl;
		}
	}
    return 0;
}
