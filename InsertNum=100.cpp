/*************************************************************************
	> File Name: InsertNum=100.cpp
	> Author: YeGuoSheng
	> Description:  Design an algorithm in 1,2,3... 9(same order) insert + or - or nothing between Numbers
Make the result == 100 output all possibilities
	> Created Time: 2019-04-09  16:01:40
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
#define N 9 

void Solve(char op[],int sum,int prevadd,int arr[],int i)
{
	if(i == N)
	{
		if(sum == 100)
		{
			cout<<arr[0];
			for(int j = 1;j < N ;j++)
			{
				if(op[j] != ' ')
				{
					cout<<op[j];
				}
				cout<<arr[j];
			}
			cout<<"=100"<<endl;
		}
		return ;
	}
	op[i] = '+';//index i insert +
	sum += arr[i];
	Solve(op,sum,arr[i],arr,i+1);//next 
	sum -= arr[i];//backtracking 

	op[i] = '-';//index i insert - 
	sum -= arr[i];
	Solve(op,sum,-arr[i],arr,i+1);//next 
	sum += arr[i];

	op[i] = ' ';
	sum -= prevadd;
	int temp;
	if( prevadd > 0)//prevadd = 5 ,arr[i] = 6 = > 56
	{
		temp = prevadd *10 + arr[i];
	}
	else//prevadd =-5  arr[i] = 6 => -56
	{
		temp =prevadd * 10 - arr[i];
	}
	sum += temp;
	Solve(op,sum,temp,arr,i + 1);
	sum -= temp;//backtracking 
	sum += prevadd;
	
}


int main()
{
	int arr[N];
	char op[N];
	for(int i = 0;i  < N; i ++)
	{
		arr[i] = i  + 1;
	}
	Solve(op,arr[0],arr[0],arr,1);
    return 0;
}
