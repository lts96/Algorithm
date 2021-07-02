#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
stack <char> st;


// 주의 사항 ! 스택 초기화 한다음 top 확인할때 stack이 empty 상태면 에러뜸
// 조건문으로 stack이 비어있지 않을때 설정해줘야됨


int main(int argc, char** argv)
{
	bool flag;
	string s = "";
	while (s != ".")
	{
		flag = true;
		getline(cin , s); 
		if (s == ".")
			break;
		for (int i = 0; i < s.length(); i++)
		{
			char temp = s.at(i);
			if (temp == '(' || temp == '[')
			{
				st.push(temp);
			}
			else if (temp == ')')
			{
				if (!st.empty())
				{
					if (st.top() == '[')
						flag = false;
					if (st.top() == '(')
						st.pop();
				}
				else
					flag = false;
			}
			else if (temp == ']')
			{
				if (!st.empty())
				{
					if (st.top() == '(')
						flag = false;
					if (st.top() == '[')
						st.pop();
				}
				else
					flag = false;
			}
		}
		if (st.empty() && flag == true)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		while (st.empty()== false)
			st.pop();
	}
	//system("pause");
	return 0;
}