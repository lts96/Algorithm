#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
// 백준에 있는 프린터 큐 문제와 동일
queue <pair <int , int>> q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0; i< priorities.size(); i++)
        q.push(make_pair(priorities[i], i));
    sort(priorities.begin(), priorities.end());
    int cnt = 0;
    for(int i= priorities.size()-1; i>= 0; i--)
    {
        int t1, t2;
        int v = priorities[i];
        while((q.front().first != v)&&(!q.empty()))
        {
            //cout << t1 << " " << t2<< endl;
            t1 = q.front().first;
            t2 = q.front().second;
            q.pop();
            q.push(make_pair(t1,t2));
        }
        t1 = q.front().first;
        t2 = q.front().second;
        q.pop();
        cnt++;
        if(t2 == location)
            answer = cnt;
    }
    return answer;
}
