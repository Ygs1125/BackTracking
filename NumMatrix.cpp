/*************************************************************************
	> File Name: NumMatrix.cpp
	> Author: YeGuoSheng
	> Description:  Fill in a square of 3 by 3 squares with 9 Numbers from 1 to 10, one for each square
Make the sum of the Numbers in all adjacent squares prime, and find the square matri
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
int arr[9] = {0};
int vis[11] ;
int CheckMatrix[][3] = {{-1},{0,-1},{1,-1},{0,-1},{1,3,-1},{2,4,-1},{3,-1},{4,6,-1},{5,7,-1}};
int counter  = 0;

void Disp()
{
	cout<<"Solution:"<<++counter<<endl;
	for(int i = 0; i < 3;i++)
	{
		for(int j = 0; j < 3;j++)
		{
			cout<<arr[3*i+j]<<" ";
		}
		cout<<endl;
	}
}

bool IsPrime(int x)
{
	for(int i = 2;i <= sqrt(x);i++)
	{
		if(x % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool Check(int pos)//check location is pos in arr  sum of close num  
{
	int i,j;
	if(pos < 0) return 0;
	for(i = 0; (j = CheckMatrix[pos][i]) >= 0;i++)
	{
		if( ! IsPrime(arr[pos] +arr[j]))
		{
			return false;
		}
	}
	return true;
}

int SelectNum(int start)
{
	for(int j = start ;j<=10;j++)
	{
		if(vis[j]) return j;
	}
	return 0;
}
int Extend(int pos)//Extend selects an unused number for the pos position, pos++
{
	arr[++pos] = SelectNum(1);
	vis[arr[pos]] = 0;
	return pos;
}

int Change(int pos)
{	
	int j;
//Select another number for the pos position. To avoid duplication, start with the next number in the original position
	while(pos >= 0 && (j = SelectNum(arr[pos] + 1)) == 0)
	{
		vis[arr[pos--]] = true;
	}
	if(pos < 0)return -1;
	vis[arr[pos]] = true;//Find an unused number j for the pos location
	arr[pos]  = j;
	vis[j] = false;
	return pos;
}

void Solve()
{
	bool ok = true;
	int pos = 0;
	arr[pos]  = 1;
	vis[arr[pos]] = 0;
	do
	{
		/* code */
		if(ok)
		{
			if(pos == 8)
			{
				Disp();
				pos = Change(pos);
			}
			else
			{
				pos = Extend(pos);
			}	
		}
		else
		{
			pos  = Change(pos);
		}
		ok = Check(pos);
		
	} while (pos >= 0);
	
}

int main()
{
	for(int i = 1;i <= 10;i++)
	{
		vis[i] = true;
	}
	Solve();
	cout<<"All counter is "<<counter<<endl;
	return 0;
}
