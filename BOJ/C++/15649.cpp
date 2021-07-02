#include <iostream>
#include <utility>
#include <math.h>
using namespace std;
int n , m;
int arr[10];
void right_rotate(int start, int end) 
{
	int last = arr[end];
	for (int i = end; i > start; i--)
		arr[i] = arr[i - 1];
	arr[start] = last;
}
void left_rotate(int start, int end)
{
	int first = arr[start];
	for (int i = start; i < end; i++)
		arr[i] = arr[i + 1];
	arr[end] = first;
}
void run(int r)
{
	if (r == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = r; i < n; i++)  // r부터 시작해야함 
	{
		right_rotate(r, i); //그냥 swap 함수로는 사전순이 안나옴 
		// 그래서 rotate 사용 
        // 왜 rotate를 하면 올바른 사전순이 되는지 생각해볼것 
		run(r + 1);
		left_rotate(r, i);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		arr[i] = i+1;
	run(0);
	return 0;
}