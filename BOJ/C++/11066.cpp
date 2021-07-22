#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int cache[501][501];
int psum[501]; // 부분합을 저장하기 위한 배열 
// 하도 못풀겠어서 구글링함 -> https://guy-who-writes-sourcecode.tistory.com/43
/*
부분합이 필요한 이유 
 = 파일 합성하는 비용 
*/
// dp[i][j]는 i장부터 j장까지 합치는데 드는 최소 비용 
vector <int> arr;
#define MAX 2100000000
void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << cache[i][j] << " ";
		cout << "\n";
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, input;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		for (int i = 0; i <= 500; i++)
			psum[i] = 0;
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> input;
			sum += input;
			psum[j] += sum;
		}
		int y;
		// for문을 이렇게 하는 이유는 갱신해나가는 방향때문
		// 이렇게 안하면 엉뚱한 방향으로 갱신됨 
		for (int d = 1; d <= n; d++)
		{
			for (int x = 1; x + d <= n; x++)
			{
				y = x + d;
				// 최솟값을 찾기 위해서 MAX를 넣어준다 
				// 미리 테이블을 초기화하면 아래 점화식 계산과정에서 오버플로우남
				cache[x][y] = MAX;
				// K 가 [i,j] 구간을 벗어나면 안된다 
				// 부분합이 더해져야되는데 이걸 생각못해서 못풀었었음 
				for (int k = x; k < y; k++)
					cache[x][y] = min(cache[x][y], cache[x][k] + cache[k + 1][y] + psum[y] - psum[x-1]);
			}
		}
		//print();
		cout << cache[1][n] << "\n";
		arr.clear();
	}
	return 0;
}
