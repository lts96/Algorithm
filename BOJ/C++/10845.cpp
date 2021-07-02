#include <iostream>
#include <string>
using namespace std;
int n;
int fp, bp , s;
int arr[30000];
void push(int n)
{
	s++;
	arr[bp] = n;
	bp++;
}
int empt()
{
	if (fp == bp)
		return 1;
	else
		return 0;
}
void pop()
{
	if (empt() == 1)
		cout << "-1" << endl;
	else
	{
		s--;
		cout << arr[fp] << endl;
		fp++;
	}
}

int size()
{
	return s;
}


int front()
{
	if (empt() == 1)
		return -1;
	else
	{
		return arr[fp];
	}
}
int back()
{
	if (empt() == 1)
		return -1;
	else
	{
		return arr[bp-1];
	}
}

int main(int argc, char** argv)
{
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			int temp;
			cin >> temp;
			push(temp);
		}
		if (str == "pop")
			pop();
		if (str == "size")
			cout << size() << endl;
		if (str == "empty")
			cout << empt() << endl;
		if (str == "front")
			cout << front() << endl;
		if (str == "back")
			cout << back() << endl;
	}
	//system("pause");
	return 0;
}