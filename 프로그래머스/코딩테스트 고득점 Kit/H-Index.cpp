#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int h = citations[n-1];
    for(int i=h; i>=0; i--)
    {
        int cnt = 0;
        for(int j=0; j<n; j++)
        {
            if(citations[j] >= i)
            {
                cnt = n-j;
                //cout << cnt << " " << i<< endl;
                break;
            }
        }
        if(cnt >= i)
        {
            answer = i;
            break;
        }
    }
    return answer;
}
