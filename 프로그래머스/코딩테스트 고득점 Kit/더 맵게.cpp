#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
priority_queue< int, vector<int>, greater<int> > pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0; i< scoville.size(); i++)
        pq.push(scoville[i]);
    int cnt = 0;
    while(!pq.empty())
    {
        if(pq.size() == 1 && pq.top() < K)
        {
            answer = -1;
            break;
        }
        if(pq.top() >= K)
        {
            answer = cnt;
            break;
        }
        else 
        {
            int t1 = pq.top();
            //cout << t1 << endl;
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            pq.push(t1 + t2 * 2);
            cnt++;
        }
    }
    return answer;
}
