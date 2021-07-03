
// 문자열 + bfs 문제 
// 사실 문자열은 별로 처리할 것도 없었음 그냥 bfs 문제다 
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
int arr[52][52];
queue<pair<int, int >> q;
int t;
bool visit[52];
int bfs(int n)
{
    int x , cnt;
    while(!q.empty())
    {
        x = q.front().first;
        cnt = q.front().second;
        visit[x] = true;
        if(x == t)
            return cnt;
        for(int i=0; i<n; i++)
        {
            if((arr[x][i] > 0) && (visit[i] == false))
                q.push(make_pair(i, cnt+1));
        }
        q.pop();
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // begin == 0,0
    int n = begin.length();
    words.insert(words.begin(),begin);
    bool finish = true;
    for(int k =0; k < words.size(); k++)
    {
        if(target.compare(words[k])==0)
        {
            finish = false;   
            t = k;
        }
    }
    if(finish == true)
        return answer;
    for(int k =0; k < words.size(); k++)
    {
        for(int i=0; i< words.size(); i++)
        {
            int cnt = 0;
            for(int j=0; j<n;j++)
            {
                if(words[i][j] == words[k][j])
                    cnt++;
            }
            if(cnt == n-1)
                arr[k][i]++;
        }   
    }
    q.push(make_pair(0,0));
    answer = bfs(words.size());
    return answer;
}
