#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) 
{
	stack<int> mystack;
	for (int i = 0; i < tokens.size(); i++)
	{
		int flag = 0, num = 0;
		char fuhao = 0;
		string::iterator it = tokens[i].begin();
		while (it < tokens[i].end())
		{
			if (*it == '-' && it + 1 < tokens[i].end())
				flag = 1;
			if (*it >= '0' && *it <= '9')
				num = num * 10 + *it - '0';
			if (*it == '+' || *it == '/' || *it == '*' || (*it == '-' && flag==0))
			{
				fuhao = *it;
			}
			it++;
		}
		if (flag == 1)
			num = -num;
		if (num == 0 && fuhao != 0)
		{
			if (fuhao == '+')
			{
				int num1 = mystack.top();
				mystack.pop();
				int num2 = mystack.top();
				mystack.pop();
				num = num2 + num1;
			}
			if (fuhao == '-')
			{
				int num1 = mystack.top();
				mystack.pop();
				int num2 = mystack.top();
				mystack.pop();
				num = num2 - num1;
			}
			if (fuhao == '*')
			{
				int num1 = mystack.top();
				mystack.pop();
				int num2 = mystack.top();
				mystack.pop();
				num = num2 * num1;
			}
			if (fuhao == '/')
			{
				int num1 = mystack.top();
				mystack.pop();
				int num2 = mystack.top();
				mystack.pop();
				num = num2 / num1;
			}
		}
		mystack.push(num);
	}
	return mystack.top();
}

int main()
{
	vector<string> num = { "4", "13", "5", "/", "+" };
	cout << evalRPN(num) << endl;
	system("pause");
	return 0;
}