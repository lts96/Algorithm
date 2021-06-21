#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
int ans = 10000000;
int **arr;
bool *check; // start를 다 뽑고 나서 안뽑은거 표시하는 용도 
int start_arr[10], link_arr[10]; // 각각 뽑은 사람 저장하기 위한 배열
int mid;
// 백준 스타트와 링크 -> 브루트 포스 + 조합 문제 , 가능한 조합의 개수 다 뽑고 
// 가능한 순서쌍끼리 덧셈 -> 최대 4천만? 
void combination( vector<int> & pick , int n ,int r )
{
	int temp, start = 0 , link = 0 , index = 0;
	if (r == 0) // pick size == r == n/2
	{
		for (int i = 0; i < pick.size(); i++)
		{
			start_arr[i] = pick[i];
			check[start_arr[i]] = true;
		}
		for (int i = 0; i < n; i++)
		{
			if (check[i] == false)
			{
				link_arr[index] = i;
				index++;
			}
		}
		for (int i = 0; i < pick.size(); i++)
		{
			for (int j = 0; j < pick.size(); j++)
			{
				start += arr[start_arr[i]][start_arr[j]];
				link += arr[link_arr[i]][link_arr[j]];
			}
		}
		if (start > link)
			temp = start - link;
		else
			temp = link - start;
		if (ans > temp)
			ans = temp;
		/*
		cout << "start ";
		for (int i = 0; i < pick.size(); i++)
		{
			cout << start_arr[i]+1 << " ";
		}
		cout << "link ";
		for (int i = 0; i < pick.size(); i++)
		{
			cout << link_arr[i]+1 << " ";
		}
		cout << "temp :" << temp << endl << endl;
		*/
		for (int i = 0; i < n; i++)
			check[i] = false;
		return;
	}
	int min; 
	if (pick.empty())
		min = 0;
	else
		min = pick.back() + 1;
	for (int i = min; i < n; i++)
	{
		pick.push_back(i);
		combination(pick, n, r - 1);
		pick.pop_back();
	}
}

int main(void)
{
	cin >> n;
	mid = n - 1;
	vector <int> pick;
	arr = new int*[n];
	check = new bool[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		check[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	combination(pick, n, n / 2);
	cout << ans << endl;
	//system("pause");
	return 0;
}