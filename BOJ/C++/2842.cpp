#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 51
int n, minh = 1000001, maxh, house;
int ans = 2100000000;
char map[MAX][MAX];
int arr[MAX][MAX];
int dx[8] = {0,0,-1,1,-1,-1,1,1};
int dy[8] = {-1,1,0,0,-1,1,-1,1};
int px, py;

/*
문제 풀이 방식 
1. 높이 입력값 중에서 중복을 제거하고 순서대로 정렬한다
2. 앞에서 정렬한 높이들을 투 포인터를 사용해서 지정
3. 지정한 높이들의 차이값으로 탐색이 가능한지 확인한다.
4. 탐색이 가능하다면 해당 고도 차이를 답이랑 갱신하고 고도 차이를 더 줄여본다
5. 탐색이 불가능하다면 고도 차이를 더 늘려서 탐색을 해본다
*/
//주어진 최저 높이와 최고 높이 사이로 방문이 가능한지 체크하는 함수
int bfs(int minH, int maxH)
{
	bool visit[MAX][MAX];
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			visit[i][j] = false;
	}
	queue <pair <int, int>> q;
	int x, y, nx, ny, visited = 0;

	q.push({ px, py });
	visit[px][py] = true;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (map[x][y] == 'K')
		{
			visited++;
			// 모든 집을 방문한 순간 더이상 돌 필요가 없으므로 바로 종료
			if (visited == house)
				return 1;
		}
		for (int i = 0; i < 8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx > n || ny < 0 || ny > n)
				continue;
			if (!visit[nx][ny] && arr[nx][ny] >= minH && arr[nx][ny] <= maxH)
			{
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector <int> height;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'P')
			{
				px = i;
				py = j;
			}
			else if (map[i][j] == 'K')
				house++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (map[i][j] != '.')
			{
				maxh = max(maxh, arr[i][j]);
				minh = min(minh, arr[i][j]);
			}
			height.push_back(arr[i][j]);
		}
	}
	// 나중에 살펴볼 고도 차이의 범위를 줄이기 위해 정렬 후 중복값을 제거
	sort(height.begin(), height.end());
	// unique 사용하려면 반드시 정렬, 그리고 unique 후에 뒤에 불필요한 값이 들어가므로
	// erase를 통해 제거해줘야한다.
	height.erase(unique(height.begin(), height.end()), height.end());

	// 정답으로 가능한 최대 높이는 우체국 + 집의 최대 높이 maxh보다 작을수 없다
	// 정답으로 가능한 최소 높이는 우체국 + 집의 최소 높이 minh보다 클 수 없다
	// 그래서 height 에서 maxh와 minh와 같은 값이 있는 인덱스 위치를 찾는다
	int maxIDX, minIDX;
	for (int i = 0; i < height.size(); i++)
	{
		if (height[i] == maxh)
			maxIDX = i;
		if (height[i] == minh)
			minIDX = i;
	}
	int start = 0, end = maxIDX, temp;
	// 투 포인터로 제한된 범위를 돌면서 해당 고도 차이로 탐색이 가능한지 확인한다.
	while (end < height.size())
	{
		while (start <= minIDX)
		{
			// 해당 조건으로 탐색이 가능하다면 최저 고도를 높인다
			temp = bfs(height[start], height[end]);
			if (!temp)
				break;
			ans = min(ans, height[end] - height[start]);
			start++;
		}
		// 탐색이 불가능하다면 최고 고도를 높여서 범위를 늘린다
		end++;
	}
	cout << ans << endl;
	return 0;
}
