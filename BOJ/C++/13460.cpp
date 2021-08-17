#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, ans = 999;
char arr[11][11];
int direct[11];
int pos[2][2];
int pos_copy[2][2];
int fx, fy;
int dx[4] = {-1,0, 1,0};
int dy[4] = { 0,-1, 0, 1};

/*
브루트포스 느낌으로 품

모든 방향을 10번 고려하면 4^10 = 백만

움직일 방향을 전부 정해놓고 정해진대로 움직이면서 어느 공이 먼저 나갔는지, 공이 제대로 나가는지 판정함

동시에 도착하는 경우를 방지하기 위해 공의 위치마다 어느 공이 먼저 움직여야되는지 구분해둠

빨간 공과 파란 공이 동시에 나가도 -1인거 주의

오른쪽으로 움직여야한다면 빨간 공과 파란 공중 더 오른쪽에 있는거부터 움직이면 된다

R하고 B 흔적이 길을 막으면 안되므로 계속 움직여주거나 첨부터 지워버리자
*/
int bfs(int d, int color)
{
    int nx, ny;
    while(1)
    {
        if (pos[color][0] == fx && pos[color][1] == fy)
        {
            // 파란색이 먼저 들어오면 
            if (color == 1)
                return -1;
            else
                return 1;
        }
        if (d == 0)
        {
            nx = pos[color][0] - 1;
            if (nx >= 0 && arr[nx][pos[color][1]] != '#')
            {
                if (nx != pos[!color][0] || pos[color][1] != pos[!color][1])
                    pos[color][0]--;
                else if(nx == pos[!color][0] && pos[color][1] == pos[!color][1] && arr[nx][pos[color][1]] == 'O')
                    pos[color][0]--;
                else
                    break;
            }
            else
                break;
        }
        else if (d == 1)
        {
            ny = pos[color][1] - 1;
            if (ny >= 0 && arr[pos[color][0]][ny] != '#')
            {
                if (ny != pos[!color][1] || pos[color][0] != pos[!color][0])
                    pos[color][1]--;
                else if (ny == pos[!color][1] && pos[color][0] == pos[!color][0] && arr[pos[color][0]][ny] == 'O')
                    pos[color][1]--;
                else
                    break;
            }
            else
                break;
        }
        else if (d == 2)
        {
            nx = pos[color][0] + 1;
            if (nx < n && arr[nx][pos[color][1]] != '#')
            {
                if (nx != pos[!color][0] || pos[color][1] != pos[!color][1])
                    pos[color][0]++;
                else if (nx == pos[!color][0] && pos[color][1] == pos[!color][1] && arr[nx][pos[color][1]] == 'O')
                    pos[color][0]++;
                else
                    break;
            }
            else
                break;
        }
        else if(d == 3)
        {
            ny = pos[color][1] + 1;
            if (ny < m && arr[pos[color][0]][ny] != '#')
            {
                if (ny != pos[!color][1] || pos[color][0] != pos[!color][0])
                    pos[color][1]++;
                else if (ny == pos[!color][1] && pos[color][0] == pos[!color][0] && arr[pos[color][0]][ny] == 'O')
                    pos[color][1]++;
                else
                    break;
            }
            else
                break;
        }
    }
    return 0;
}
void select(int idx, int prev)
{
    if (idx == 10)
    {
        pos[0][0] = pos_copy[0][0];
        pos[0][1] = pos_copy[0][1];
        pos[1][0] = pos_copy[1][0];
        pos[1][1] = pos_copy[1][1];
        int flag1 = 0, flag2 = 0;
        int time = 0;
        for (int i = 0; i < 10; i++)
        {
            // 상
            flag1 = flag2 = 0;
            time = i;
            if (direct[i] == 0)
            {
                if (pos[0][0] > pos[1][0])
                {
                    flag2 = bfs(direct[i], 1);
                    flag1 = bfs(direct[i], 0);
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
                else
                {
                    flag1 = bfs(direct[i], 0);
                    flag2 = bfs(direct[i], 1);
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
            }
            // 좌
            else if (direct[i] == 1)
            {
                if (pos[0][1] > pos[1][1])
                {
                    flag2 = bfs(direct[i], 1);
                    flag1 = bfs(direct[i], 0);
                    
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
                else
                {
                    flag1 = bfs(direct[i], 0);
                    flag2 = bfs(direct[i], 1);
                    
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
            }
            // 하
            else if (direct[i] == 2)
            {
                if (pos[0][0] > pos[1][0])
                {
                    flag1 = bfs(direct[i], 0);
                    flag2 = bfs(direct[i], 1);
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
                else
                {
                    flag2 = bfs(direct[i], 1);
                    flag1 = bfs(direct[i], 0);
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
            }
            // 우
            else if (direct[i] == 3)
            {
                if (pos[0][1] > pos[1][1])
                {
                    flag1 = bfs(direct[i], 0);
                    flag2 = bfs(direct[i], 1);
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
                else
                {
                    flag2 = bfs(direct[i], 1);
                    flag1 = bfs(direct[i], 0);
                    if (flag1 == 1 || flag2 == -1)
                        break;
                }
            }
        }
        if (flag1 == 1 && flag2 != -1)
        {
            ans = min(time + 1, ans);
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        // 이전 방향과 똑같거나 이전 방향에서 바로 돌아가는 경우는 제외
        if (i != prev)
        {
            direct[idx] = i;
            select(idx + 1, i);
        }
    }
    return;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'O')
            {
                fx = i;
                fy = j;
            }
            else if (arr[i][j] == 'R')
            {
                pos[0][0] = pos_copy[0][0]= i;
                pos[0][1] = pos_copy[0][1] = j;
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'B')
            {
                pos[1][0] = pos_copy[1][0] = i;
                pos[1][1] = pos_copy[1][1] = j;
                arr[i][j] = '.';
            }
        }
    }

    select(0, -1);
    if (ans != 999)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
