#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501][501];
int cache[501][501];
// 점화식만 잘 생각하면 되는 dp문제 
int dp(int x,int y)
{
    if(x < 0 || y < 0)
        return 0;
    if(arr[x][y] == 0)
        return 0;
    if(cache[x][y] != 0)
        return cache[x][y];
    return cache[x][y] = arr[x][y] + max(dp(x+1,y) , dp(x+1, y+1));
}
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int m = 0;
    for(int i=0; i<triangle.size(); i++)
    {
        for(int j=0; j<triangle[i].size(); j++)
            arr[i][j] = triangle[i][j];
    }
    answer = dp(0,0);
    return answer;
}
