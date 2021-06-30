#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
int qsize = 0;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    int s,t;
    for(int i=0; i< operations.size(); i++)
    {
        if(operations[i][0] == 'I')
        {
            s = operations[i].size();
            string temp = operations[i].substr(2,s-2);
            t = stoi(temp);
            //cout << t << endl;
            minq.push(t);
            maxq.push(t);
            qsize++;
        }
        
        else 
        {
            if(qsize > 0)
            {
                string temp = operations[i];
                if(temp.compare("D 1") == 0 && !maxq.empty())
                    maxq.pop();
                else if(temp.compare("D -1") == 0 &&!minq.empty()) 
                    minq.pop();
                qsize--;
            }
            // 큐가 완전히 비었다가 다시 채워질때 오류남  반드시 초기화 필요
            if(qsize == 0)
            {
                while(!maxq.empty())
                    maxq.pop();
                while(!minq.empty())
                    minq.pop();
            }
        }
    }
    
    if(qsize == 1)
    {
        answer[0] = maxq.top();
        answer[1] = maxq.top();
    }
    else if(qsize > 1)
    {
        answer[0] = maxq.top();
        answer[1] = minq.top();
    }
    return answer;
}
