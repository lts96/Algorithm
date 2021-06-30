#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
queue<pair<int, int>> q;
int arr[200];
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0; i< progresses.size(); i++)
        q.push(make_pair(progresses[i], speeds[i]));
    int day = 0;
    while(!q.empty())
    {
        int v = q.front().first;
        int s = q.front().second;
        v = v + day * s;
        //cout << s << endl;
        
        while(v < 100)
        {
            day++;
            v = v + s;
        }
        arr[day]++;
        q.pop();
    }
    for(int i=0; i<200; i++)
    {
        if(arr[i]>0)
            answer.push_back(arr[i]);
    }
    return answer;
}
