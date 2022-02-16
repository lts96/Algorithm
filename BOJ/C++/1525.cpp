#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
using namespace std;
int ans = -1;
string start, last = "123456780";
queue <pair <string, int>> q;
set <string> visit;
int dx[4] = { -1, 1, 0,0 };
int dy[4] = { 0,0,-1, 1 };
// 문자열로 상태를 저장한다는 것과 셋을 통해서 상태 방문처리가 가능하다는것만 떠올리면 구현은 간단한 문제 
void print(string s)
{
	cout << endl;
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] << " ";
		if (i == 2 || i == 5 || i == 8)
			cout << endl;
	}
}
// 메모리 한도가 적으므로 최대한 메모리를 아껴쓰기 위해 string으로 2차원 배열 표현
// 그리고 방문체크는 set을 사용해서 문자열이 중복되는지 체크함 
// 가장 시간이 오래걸리는 케이스는 답이 -1인 경우
// 최대한 탐색 depth도 줄이기 위해서 다음 노드로 넘어가기전에 정답체크를 진행한다
void bfs()
{
	string s, next;
	int d = 0, idx = 0;
	int x, y, nx, ny;
	char temp;
	if (start.compare(last) == 0)
	{
		ans = 0;
		return;
	}
	q.push({ start, 0 });
	visit.insert(start);
	while (!q.empty())
	{
		s = q.front().first;
		d = q.front().second;
		//print(s);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '0')
			{
				idx = i;
				break;
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			x = idx / 3;
			y = idx % 3;
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
				continue;
			next = s;
			temp = next[idx];
			next[idx] = next[nx * 3 + ny];
			next[nx * 3 + ny] = temp;
			if (visit.find(next) == visit.end())
			{
				if (next.compare(last) == 0)
				{
					ans = d + 1;
					return;
				}
				visit.insert(next);
				q.push({ next, d + 1 });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	string input;
	for (int i = 0; i < 9; i++)
	{
		cin >> input;
		start += input;
	}
	bfs();
	cout << ans << "\n";
	return 0;
}
