#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[31];

// 체육복 없으면 앞번호한테부터 빌림 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=0; i<lost.size(); i++)
        arr[lost[i]]--;
    for(int i=0; i<reserve.size(); i++)
        arr[reserve[i]]++;
    for(int i=0; i<=30; i++)
    {
        if(arr[i] >= 0)
            continue;
        else if(arr[i] == -1)
        {
            if(arr[i-1] == 1)
            {
                arr[i-1]--;
                arr[i]++;
            }
            else if(arr[i+1] == 1)
            {
                arr[i+1]--;
                arr[i]++;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        //cout << arr[i]<<" ";
        if(arr[i] >=0)
            answer++;
    }
    return answer;
}
