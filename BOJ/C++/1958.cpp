#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define MAX 101
string s1, s2, s3;
int m;
int cache[MAX][MAX][MAX];
void clear()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
				cache[i][j][k] = -1;
		}
	}
}

// lcs 응용문제 

// 틀렸던 이유는 같은 문자가 반복되는 경우 이미 lcs에 들어있는 
// 케이스가 한번더 계산이 됨  
// 기존 lcs에 들어있는 경우랑 아예 x, y, z가 달라야 +1하는걸로 고침
int dp(int x, int y, int z)
{
	if (x < 0 || y < 0 || z < 0)
		return 0;
	if (cache[x][y][z] != -1)
		return cache[x][y][z];
	int temp[7];
	int result = 0, idx = 0;
	temp[0] = dp(x - 1, y, z);
	temp[1] = dp(x, y - 1, z);
	temp[2] = dp(x, y, z - 1);
	temp[3] = dp(x - 1, y - 1, z);
	temp[4] = dp(x - 1, y, z - 1);
	temp[5] = dp(x, y - 1, z - 1);
	temp[6] = dp(x - 1, y - 1, z - 1);
	for (int i = 0; i < 7; i++)
	{
		if (temp[i] > m)
			continue;
		if (result <= temp[i])
		{
			result = temp[i];
			idx = i;
		}
	}
	if (s1[x] == s2[y] && s2[y] == s3[z])
	{
		//cout << x << " " << y << " " << z << " " << idx << endl;
		if (result == 0)
			result++;
			
		else if (idx == 6)
		{
			result++;
			//cout << x << " " << y << " " << z << endl;
		}
	}
	// 가장 작은 문자열의 길이를 초과하는 lcs는 없다 
	if (result > m)
		result = m;
	return cache[x][y][z] = result;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s1 >> s2 >> s3;
	clear();
	m = min(min(s1.size(), s2.size()), s3.size());
	cout << dp(s1.size() - 1, s2.size() - 1, s3.size() - 1) << "\n";
	return 0;
}
