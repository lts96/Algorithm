#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (int i = 0; i < commands.size(); i++)
    {
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];

        temp.assign(array.begin() + a - 1, array.begin() + b);

        sort(temp.begin(), temp.end());
        answer.push_back(temp[c - 1]);
        temp.clear();
    }
    return answer;
}