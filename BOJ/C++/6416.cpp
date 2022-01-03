#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define MAX 100009
int cnt[MAX];
bool visit[MAX];
bool check[MAX];
vector <int> arr[MAX];
int visit_cnt, flag;

/*
반례 : 0 0 -1 -1 
Case 1 is a tree.
*/

void clear()
{
	for (int i = 0; i < MAX; i++)
	{
		cnt[i] = 0;
		check[i] = false;
		visit[i] = false;
		arr[i].clear();
	}
	return;
}
void dfs(int idx)
{
	int next;
	visit[idx] = true;
	visit_cnt++;
	for (int i = 0; i < arr[idx].size(); i++)
	{
		next = arr[idx][i];
		if (visit[next] == false)
			dfs(next);
		else
			flag++;
	}
	return;
}
int run()
{
	int node_cnt = 0, root, root_cnt = 0;
	visit_cnt = 0;
	// 조건 2번 판별용 -> 이미 방문한 노드를 재방문 시도시 체크
	flag = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (check[i])
		{
			node_cnt++;
			if (cnt[i] == 0)
			{
				root = i;
				root_cnt++;
			}
		}
	}
	// 빈 트리일때는 트리라고 해야함 -> 예외처리
	if (node_cnt == 0)
		return 1;
	// 1번 조건 확인
	if (root_cnt != 1)
		return -1;
	// 2번 조건과 3번 조건 확인용
	dfs(root);
	// 3번 조건 확인
	if (visit_cnt != node_cnt)
		return -1;
	// 2번 조건 확인
	if (flag > 0)
		return -1;
	return 1;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 0, b = 0, ret, k = 1;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			ret = run();
			if (ret < 0)
				cout << "Case " << k << " is not a tree.\n";
			else
				cout << "Case " << k << " is a tree.\n";
			clear();
			k++;
		}
		else if (a == -1 && b == -1)
			break;
		else
		{
			arr[a].push_back(b);
			cnt[b]++;
			check[a] = true;
			check[b] = true;
		}
	}
	return 0;
}
