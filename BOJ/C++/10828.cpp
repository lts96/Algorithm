#include <iostream>
#include <stdlib.h>
#include <string>
#pragma warning (disable:4996)
using namespace std;
int n; 
int index;
int stack_size;
int arr[10001];
void push(int n)
{
	index++;
	arr[index] = n;
	stack_size++;
}
int top()
{
	if (stack_size > 0)
		return arr[index];
	else
		return -1;
}
int pop()
{
	if (stack_size > 0)
	{
		int temp = arr[index];
		stack_size--;
		index--;
		return temp;
	}
	else
		return -1;
}
int empty()
{
	if (stack_size == 0)
		return 1;
	else
		return 0;
}
int size()
{
	return stack_size;
}

int main(void)
{
	string input; 
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> temp;
			push(temp);
		}
		if (input == "top")
			cout << top() << endl;
		if (input == "pop")
			cout << pop() << endl;
		if (input == "empty")
			cout << empty() << endl;
		if (input == "size")
			cout << size() << endl;
	}
	//system("pause");
	return 0;
}