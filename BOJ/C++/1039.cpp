#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define MAX 1000003
int start, k, ans = -1, n;
map <string, int> m;
string swap(string s, int a, int b)
{
	char temp;
	temp = s[a];
	s[a] = s[b];
	s[b] = temp;
	return s;
}
/*
	반례
	40069 3
	ans : 96400

	100 2
	ans : 100

	90 2
	ans : -1

	999999 8
	ans : 999999
*/
// 이 문제에서 핵심은 각 단계에서 중복된 숫자가 있을 필요가 없다는 것
// 기존 bfs가 아니라 그냥 단순히 생각해보자
// 결국 k번 뒤집었을때 남은 숫자들 중 제일 큰 거만 찾으면 됨 
// 중간 단계에서 중복만 없다면 모든 경우의 수를 다 해봐도 10만을 넘을리가 없음
// 일반 bfs로 구현할 경우 2가지 문제점이 발생
// 중복 방문을 차단할 경우 올바른 정답을 못찾는 경우 있음
// 중복 방문을 허용할 경우 메모리 터짐 
// bfs처럼 하되 각 depth 별로 중복된걸 지워나가야함
void bfs()
{
	int next, cnt, t;
	string curr, temp;
	string s = to_string(start);
	n = s.size();
	queue <string> q;
	q.push(s);
	// bfs를 꼭 while로 처리한다는 고정관념 버리기

	// k번 뒤집기
	for (int h = 0; h < k; h++)
	{
		// 큐 돌면서 가장 앞 찾아오기
		t = q.size();
		for (int g = 0; g < t; g++)
		{
			curr = q.front();
			q.pop();
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					temp = swap(curr, i, j);
					if (temp[0] == '0')
						continue;
					// 이전에 나온적 없으면 큐에 삽입
					if (m.find(temp) == m.end())
					{
						m.insert({ temp, 0 });
						q.push(temp);
					}
				}
			}
		}
		// 방문 처리를 초기화
		m.clear();
	}
	// 마지막까지 큐에 남은 숫자는 k번 swap이 가능한 숫자들
	// 이중에서 최대를 찾으면 된다
	if (q.empty())
		return;
	t = q.size();
	for (int i = 0; i < t; i++)
	{
		ans = max(ans, stoi(q.front()));
		q.pop();
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> start >> k;
	bfs();
	cout << ans << endl;
	return 0;
}
