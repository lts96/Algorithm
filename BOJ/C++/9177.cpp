#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
/*
Interleaving string problem
단순히 앞에서 읽어나가는 투포인터 방식은 2번째 예제에서 걸림
첫번째 제출에서 틀린 이유 : 예제 2번의 t는 양쪽 단어 모두 사용가능 -> 이럴때 2가지 경로를 모두 탐색해야하는데
내가 구현한건 한쪽 방향만 탐색하므로 탐색을 못하는 경우가 발생

dp로도 풀 수 있고 최소 편집문제랑 비슷하니 반드시 해보자
*/
string s1, s2, s3;

// bfs로 문자열 뒤부터 앞으로 가면서 탐색
// idx는 3번째 문자열에서 현재 보고 있는 인덱스
// idx1은 1번째 문자열에서 ~
// idx2은 2번째 문자열에서 ~
// 이 3가지를 상태값으로 잡고 이미 방문한 곳은 지워가면서 탐색하면 된다
int bfs(int a, int b, int c)
{
	queue <pair <int ,pair <int, int >>> q;
	q.push({ a,{b,c} });
	int idx1, idx2, idx;
	bool visit[210][210];
	for (int i = 0; i < 210; i++)
	{
		for (int j = 0; j < 210; j++)
			visit[i][j] = false;
	}
	while (!q.empty())
	{
		idx = q.front().first;
		idx1 = q.front().second.first;
		idx2 = q.front().second.second;
		//cout << idx << " " << idx1 << " " << idx2 << endl;
		q.pop();
		if (idx == 0 && idx1 == 0 && idx2 == 0)
			return 1;
		if (s1[idx1 - 1] == s3[idx - 1])
		{
			if (idx1 - 1 >= 0 && !visit[idx1 - 1][idx2])
			{
				visit[idx1 - 1][idx2] = true;
				q.push({ idx - 1, {idx1 - 1, idx2} });
			}
		}
		if (s2[idx2 - 1] == s3[idx - 1])
		{
			if (idx2 - 1 >= 0 && !visit[idx1][idx2 - 1])
			{
				visit[idx1][idx2 - 1] = true;
				q.push({ idx - 1, {idx1, idx2 - 1} });
			}
		}
	}
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int ans, m, pos1, pos2, empty;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ans = 0;
		cin >> s1 >> s2 >> s3;
		ans = bfs(s3.size(), s1.size(), s2.size());
		if (ans)
			cout << "Data set "<< i + 1 << ": yes\n";
		else
			cout << "Data set " << i + 1 << ": no\n";
	}
	return 0;
}
