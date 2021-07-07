#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define DIV  1000000007
long long arr[101][101];
// 전형적인 dp 문제였음 
long long dp(int x, int y)
{
    if(x < 0 || y < 0)
        return 0; 
    if(arr[x][y] == -1)
        return 0;
    else if(arr[x][y] > 0)
        return arr[x][y] % DIV;
    else if(arr[x][y] == 0)
    {
        long long left = dp(x-1,y);
        long long up = dp(x, y-1);
        arr[x][y] = (left + up) % DIV; 
        //cout << "x : " << x  << " y : " << y << " z: " << arr[x][y]<< endl;
        return arr[x][y];   
    }
    
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    arr[0][0] =1;
    for(int i=0; i<puddles.size(); i++)
        arr[puddles[i][0]-1][puddles[i][1]-1] = -1;
    dp(m-1,n-1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << arr[j][i] <<" ";
        cout << endl;
    }
    answer = arr[m-1][n-1];
    return answer;
}
