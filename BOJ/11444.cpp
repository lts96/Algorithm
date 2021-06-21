#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;
typedef unsigned long long ll;
ll n;
vector <ll> pw;
ll matrix[2][2], arr[2][2], ans[2][2], f[2][2]; // 피보나치 수 저장
#define div 1000000007

//행렬 곱셉,제곱 구현은 10830번 참고

ll multiple(int x, int y) // 행렬 곱셈 계산
{
	ll temp = 0;
	for (int i = 0; i < 2; i++)
		temp = (temp + (arr[x][i] * arr[i][y])) % div;
	return temp;
}
void clear()  // 초기화용 
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			arr[i][j] = matrix[i][j];
	}
	return;
}
void print()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return;
}
void run(ll target)  // 행렬 제곱
{
	int cnt = 0;
	ll arr2[2][2];
	while (cnt != target)  //arr을 계속 제곱 
	{
		cnt++;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				arr2[i][j] = multiple(i, j);
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				arr[i][j] = arr2[i][j];
		}
	}
	//print();
	//이러고 ans와 arr을 곱 
	ll arr3[2][2];
	for (int i = 0; i < 2; i++)  //행렬 곱셈하면서 값이 변함 -> 방지하기 위해 arr3으로 분리
	{
		for (int j = 0; j < 2; j++)
		{
			ll temp = 0;
			for (int k = 0; k < 2; k++)
				temp = (temp + (ans[i][k] * arr[k][j])) % div;
			arr3[i][j] = temp;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			ans[i][j] = arr3[i][j];
	}
	clear();
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	f[0][0] = arr[0][0] = matrix[0][0] = 0;
	f[1][0] = f[0][1] = arr[0][1] = arr[1][0] = arr[1][1] = 1;
	matrix[0][1] = matrix[1][0] = matrix[1][1] = 1;
	ans[0][0] = ans[1][1] = 1;
	ans[0][1] = ans[1][0] = 0;
	f[1][1] = 2;
	int p = 59;
	while (n > 1)
	{
		ll temp = pow(2, p);
		if (n / temp)
		{
			n -= temp;
			pw.push_back(p);
		}
		p--;
	}
	if (n == 1)
		pw.push_back(0);
	for (int i = 0; i < pw.size(); i++)
	{
		//cout << pw[i] << endl;
		run(pw[i]);
	}
	/*
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	*/
	ll result = f[0][0] * ans[0][0] + f[0][1] * ans[1][0];
	cout << result << "\n";
	return 0;
}

