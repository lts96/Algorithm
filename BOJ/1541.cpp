#include <iostream>
#include <string>
#include <vector>
// 1541 잃어버린 괄호 -> 그리디인데 일단 + 붙은 놈들끼리 묶는게 이득
// + 먼저 다 연산하고 - 하면 될듯

using namespace std;
int n, k ;
long long ans;
vector <int> num;
vector <char> operate;
int main(void)
{
	string str , sub;
	char temp;
	cin >> str; 
	int start = 0 ,size, count = 0; // 내가 놓쳤던 부분 , 입력이 연산자 없이 그냥 숫자만 들어올 수 있음
	//일단 숫자랑 연산자 분리 
	for (int i = 0; i < str.length(); i++)
	{
		temp = str.at(i);
		if (temp == '-')
		{
			sub = str.substr(start, i);
			int a = stoi(sub, nullptr, 10);
			num.push_back(a);
			start = i + 1;
			operate.push_back(temp);
            count++;
		}
		if (temp == '+')
		{
			sub = str.substr(start, i);
			int a = stoi(sub, nullptr, 10);
			num.push_back(a);
			start = i + 1;
			operate.push_back(temp);
            count++;
		}
	}
    if(count==0)
    {
        ans = stoi(str,nullptr,10); 
        cout << ans << endl;
        return 0;
    }
	sub = str.substr(start, str.size()-1);
	int a = stoi(sub, nullptr, 10);
	num.push_back(a);

	// 우선 + 부터 연산 
	size = operate.size();
	for (int i = 0; i < size; i++)
	{
		if (operate[i] == '+')
		{
			num [i+1]= num[i] + num[i + 1];
			num[i] = 0;
		}
	}
	vector <int> ::iterator iter;
	for (iter = num.begin(); iter != num.end(); iter++)
	{
		if (*iter == 0)
		{
			num.erase(iter);
			iter = num.begin()-1;
		}
	}
	
	vector <char> ::iterator iter2;
	for (iter2 = operate.begin(); iter2 != operate.end(); iter2++)
	{
		if (*iter2 == '+')
		{
			operate.erase(iter2);
			iter2 = operate.begin()-1;
		}
	}

	ans = num[0];
	for (int i = 0; i < operate.size(); i++)
	{
		if (operate[i] == '-')
		{
			ans = ans - num[i + 1];
			//cout << ans << endl;
		}
	}
	/*
	cout << "number :";
	int x = num.size() , y= operate.size();
	for (int i = 0; i < x; i++)
	{
		if (!num.empty())
		{
			cout << num[i] << " ";
		}
	}
	cout << endl;
	cout << "oper :";
	for (int i = 0; i < y; i++)
	{
		if (!operate.empty())
		{
			cout << operate[i] << " ";
		}
	}
	cout << endl;
	*/
	cout << ans << endl;
	//system("pause");
	return 0;
}