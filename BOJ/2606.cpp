#include <iostream>
#include <stdlib.h> // 순환 구조일때가 문제  쓸데없이 개수 추가됨  
using namespace std; 
int comp; 
int connect; 
int * answer;
int ** graph;
void dfs( int a, int b)
{
	for(int j=0;j<comp;j++)
	{
		if(graph[a][j]!=0)
		{
			answer[j]=1;
			graph[a][j]=0; 
			graph[j][a]=0; 
			
			dfs(j,b); 
		}
	}	
	return;
}
int main(void)
{
	int ca,cb;
	int sum=0;
	int start=0; int end=0;
	cin>> comp;
 	graph = (int **)malloc(sizeof(int *)*comp); 
 	for(int i=0;i<comp;i++)
 	graph[i] = (int *)malloc(sizeof(int)*comp);
	answer = (int *)malloc(sizeof(int)*comp);
	cin>> connect;
	for(int i=0;i<comp;i++)
	{
		answer[i]=0;
		for(int j=0;j<comp;j++)
		graph[i][j]=0;	
	} 
	for(int i=0;i<connect; i++)
	{
		cin>>ca; 
		cin>>cb; 
		graph[ca-1][cb-1]=1;
		graph[cb-1][ca-1]=1;
	}
	dfs(start,end);
	for(int i=1;i<comp;i++)
	sum=sum+answer[i];
	cout <<sum;
	return 0;
}