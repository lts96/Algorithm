#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int hx, hy, fx, fy;
vector <pair <int, int>> arr;
queue <pair <int, int>> q;
bool visit[200];

// bfs 구현 문제 
// 집, 편의점, 도착장소를 노드로 보고 탐색 
// 어차피 맥주는 항상 20개 충전이므로 맥주 개수를 따로 셀 필요없이 거리가 1000이하인지만 체크하면 된다 

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
void bfs()
{
    int x, y, d, nx, ny;
    for (int i = 0; i < 200; i++)
        visit[i] = false;
    bool flag = false;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        if (x == fx && y == fy)
        {
            flag = true;
            break;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            nx = arr[i].first;
            ny = arr[i].second;
            d = dist(x, y, nx, ny);
            if (visit[i] == false && d <= 1000)
            {
                visit[i] = true;
                q.push({ nx, ny });
            }
        }
        q.pop();
    }
    if (flag)
        cout << "happy\n";
    else
        cout << "sad\n";
    while (!q.empty())
        q.pop();
    return;
}
int main(void)
{
    int test,a,b;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        cin >> n;
        cin >> hx >> hy;
        arr.push_back({ hx,hy });
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            arr.push_back({ a,b });
        }
        cin >> fx >> fy;
        arr.push_back({ fx,fy });
        visit[0] = true;
        q.push({ hx,hy });
        bfs();
        arr.clear();
    }
    return 0;
}
