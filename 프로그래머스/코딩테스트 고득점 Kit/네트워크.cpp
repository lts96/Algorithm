#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = {0,0,-1,1}; 
int dy[4] = {-1,1,0,0};
queue<pair <int , int>> q;
int arr[201][201];
int cnt;
int visit[201];
int m;

// 탐색 문제 
void dfs(int x, int v)
{
    if(visit[x])
        return;
    visit[x] = v;
    for(int i=0; i<m; i++)
    {
        if(arr[x][i] == 1 && visit[i] == 0)
            dfs(i,v);
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    m =n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            arr[i][j] = computers[i][j];
    }
    for(int i=0; i<n; i++)
        dfs(i, i+1);
    
    int temp = 0;
    sort(visit, visit+n);
    for(int i=0; i<n; i++)
    {
        if(visit[i]!= 0 && visit[i] != temp)
        {
            temp = visit[i];
            cnt++;
        }
    }
    //for(int i=0; i<n; i++)
        //cout << visit[i] << " ";
    answer = cnt;
    return answer;
}
