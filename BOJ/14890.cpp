#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int length, n , ans;
int arr[101][101];
bool visit[101][101];
int check_road(int num , bool flag)  // 가로인지 세로인지 구분
{
	// 높이 차이가 1이 넘는지 검사 
	for (int i = 0; i < n-1; i++)
	{
		if (flag)
		{
			if (abs(arr[num][i] - arr[num][i + 1]) > 1)
				return 0;
		}
		else
		{
			if (abs(arr[i][num] - arr[i + 1][num]) > 1)
				return 0;
		}
	}
	// 몇개가 연속하는지 기록 
	vector <int> v(n, 0);
	int cnt = 1 , temp;
	for (int i = 0; i < n-1; i++)
	{
		if (flag)
		{
			if (arr[num][i] != arr[num][i + 1])
			{
				temp = cnt;
				for (int j = 0; j < cnt; j++)
					v[i - j] = temp;
				cnt = 0;
			}
		}
		else
		{
			if (arr[i][num] != arr[i+1][num])
			{
				temp = cnt;
				for (int j = 0; j < cnt; j++)
					v[i - j] = temp;
				cnt = 0;
			}
		}
		cnt++;
		if (i + 1 == n - 1)
		{
			temp = cnt;
			for (int j = 0; j < cnt; j++)
				v[i + 1 - j] = temp;
			cnt = 0;
		}
	}
	/*
	cout << num+1 << " : ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	*/
	// 경사로 놓기 
	for (int i = 0; i < n - 1; i++)
	{
		if (flag)  // 가로
		{
			if (arr[num][i] < arr[num][i + 1])
			{
				if (v[i] < length) // 경사로 공간이 안나올때
					return 0;
				// 경사로 설치 

				// 여기서 d값이 문제 
				int d = v[i] - length , t = v[i]; 
				for (int j = 0; j < t; j++)
				{
					if (i - j < 0)
						return 0;
					visit[num][i - j] = true;
					v[i - j] = d;
				}
			}
			else if(arr[num][i] > arr[num][i + 1])
			{
				if (v[i+1] < length) 
					return 0;
				int d = v[i+1] - length , t = v[i+1];
				for (int j = 0; j < t; j++)
				{
					if (i + 1 + j > n - 1)
						return 0;
					visit[num][i + 1 + j] = true;
					v[i + 1 + j] = d;
				}
			}
		}
		else
		{
			if (arr[i][num] < arr[i + 1][num])
			{
				if (v[i] < length) // 경사로 공간이 안나올때
					return 0;
				int d = v[i] - length , t = v[i];
				for (int j = 0; j < t; j++)
				{
					if (i - j < 0)
						return 0;
					visit[i - j][num] = true;
					v[i - j] = d;
				}
			}
			else if (arr[i][num] > arr[i + 1][num])
			{
				if (v[i + 1] < length)
					return 0;
				int d = v[i+1] - length , t = v[i+1];
				for (int j = 0; j < t; j++)
				{
					if (i + 1 + j > n - 1)
						return 0;
					visit[i + 1 + j][num] = true;
					v[i + 1 + j] = d;
				}
			}
		}
	}
	return 1;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> length;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	int result;
	for (int i = 0; i < n; i++)   // 다른 방향의 도로를 같이 하면 겹칠수도 
	{
		result = check_road(i, true);
		//cout << "가로 " << i + 1 << " : " << result << endl;
		ans += result;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[i][j] = false;
	}
	for (int i = 0; i < n; i++)
	{
		result = check_road(i, false);
		//cout << "세로 " << i + 1 << " : " << result << endl;
		ans += result;
	}
	cout << ans << endl;
	return 0;
}