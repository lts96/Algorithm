#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
/*
9
7 4 8 2 5 1 3 9 6
7 8 4 5 2 9 6 3 1

11
8 4 2 5 9 1 10 6 3 7 11
8 4 9 5 2 10 6 11 7 3 1
*/
using namespace std;
int n, cnt;
int in[100001];
int post[100001];
// 함수 인자 설명 
// 왼쪽 sub tree 시작점 , 끝점 , 오른쪽 sub tree 시작점 , 끝점 , 현재 루트 정점 번호
// 현재 루트 정점이 post에서 차지하는 index 번호 
void make_tree(int s , int d , int index)
{
	int root = post[index];
	if (root == 0)
		return;
	cnt++;
	if (cnt <= n)
		cout << root << " ";
	else
		return;
	int pivot = -1;
	if ((s < 1) || (d > n))
		return;
	for (int i = s; i <= d; i++)  // inorder에서 root 위치 찾기
	{
		if (root == in[i])
		{
			pivot = i;
			break;
		}
	}
	if (pivot == -1)
		return;
	int left = pivot - s;   // 왼쪽 subtree 노드 개수
	int right = d - pivot;  // 오른쪽 subtree 노드 개수
	if (left > 0)
		make_tree(s , pivot -1 , index - right -1);  // 3번째 인자 문제
	if (right > 0)
		make_tree(pivot + 1, d, index -1); 
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> in[i];
	for (int i = 1; i <= n; i++)
		cin >> post[i];
	make_tree(1,n,n);
	return 0;
}