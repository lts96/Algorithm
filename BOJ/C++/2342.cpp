#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 2100000000
int n,ans;
int arr[100003];
int cache[100003][5][5];
// 2차원으로만 하려면 재귀가 무한루프를 돈다
// 순서대로 밟아야 하므로 상태정보는 (순서, 왼발 , 오른발) 3차원이 필요
// 초기 발 상태를 시작점으로 잡아야한다
// 항상 점화식을 잘 생각해보자 -> 나중에 반드시 다시 풀어볼것
int step(int prev, int next)
{
    if (prev == next)
        return 1;
    if (prev == 0)
        return 2;
    else if (prev == 1)
    {
        if (next == 2 || next == 4)
            return 3;
        else if (next == 3)
            return 4;
    }
    else if (prev == 2)
    {
        if (next == 1 || next == 3)
            return 3;
        else if (next == 4)
            return 4;
    }
    else if (prev == 3)
    {
        if (next == 2 || next == 4)
            return 3;
        else if (next == 1)
            return 4;
    }
    else if (prev == 4)
    {
        if (next == 1 || next == 3)
            return 3;
        else if (next == 2)
            return 4;
    }
    return 0;
}
int dp(int idx, int left, int right)
{
    int ret = MAX;
    int w1, w2;
    if (idx == n)
        return 0;
    if (cache[idx][left][right] != -1)
        return cache[idx][left][right];
    w1 = step(left, arr[idx]);
    w2 = step(right, arr[idx]);
    //cout << w1 << " " << w2 << endl;
    ret = min(dp(idx + 1, arr[idx], right) + w1, dp(idx + 1, left, arr[idx]) + w2);
    return cache[idx][left][right] = ret;
}
int main(void)
{
    int input;
    while (1)
    {
        cin >> input;
        if (input == 0)
            break;
        arr[n] = input;
        n++;
    }
    for (int k = 0; k < 100003; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                cache[k][i][j] = -1;
        }
    }
    if (n == 0)
        ans = 0;
    else if (n == 1)
        ans = 2;
    else
        ans = dp(0, 0, 0);
    cout << ans << endl;
    return 0;
}
