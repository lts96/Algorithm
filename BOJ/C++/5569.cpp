#include <iostream>
#include <vector>
using namespace std;
int w, h;
int cache[101][101][2][2];
#define div 100000
// 4가지 케이스를 나눠서 생각해야된다 
// 위에서 왔고 다음에 회전 가능 [0][0] , 불가능 [0][1]
// 옆에서 왔고 다음에 회전 가능 [1][0] , 불가능 [1][1]
// 중간 덧셈에 나머지 연산 안해줘서 계속 오버플로우남  
int main(void)
{
	int ans = 0;
	cin >> w >> h;
	for (int i = 1; i <= h; i++)
		cache[i][1][0][0] = 1;
	for (int i = 1; i <= w; i++)
		cache[1][i][1][0] = 1;
	if (w == 1 && h == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	// 어차피 1,1 부터 시작해서 갱신해가므로 이중 for로도 가능 (bottom - up?) 
	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			cache[i][j][0][0] = (cache[i - 1][j][0][0] + cache[i-1][j][0][1]) % div;
			cache[i][j][1][0] = (cache[i][j - 1][1][0] + cache[i][j - 1][1][1]) % div;

			// 회전이 불가한 경우는 이미 전에 회전을 했을때 
			cache[i][j][0][1] = cache[i - 1][j][1][0];
			// 이것도 회전이 불가능한 경우 -> 이전 좌표에서 방향이 변함
			cache[i][j][1][1] = cache[i][j - 1][0][0];
		}
	}
	ans = (cache[h][w][0][0] + cache[h][w][0][1] + cache[h][w][1][0] + cache[h][w][1][1]) % div;
	cout << ans << endl;
	return 0;
}
