#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
vector<vector<string>> num;
vector<int> use;
vector<int> ptr;
int number;
void queen(int n)
{
	if (n == number)
	{
		string arr;
		for (int i = 0; i < n; i++)
			arr += '.';
		num.resize(num.size() + 1);
		//num[num.size() - 1].resize(n);
		for (int i = 0; i < n; i++)
		{
			num[num.size() - 1].push_back(arr);
			num[num.size() - 1][i][ptr[i]-1] = 'Q';
		}
		return;
	}

	for (int i=0;i<number;i++)
	{
		if (use[i] == 0)
		{
			int flag = true;
			for (int k = 0; k < n; k++)
			{
				if (abs(i+1-ptr[k]) == abs(k-n))	
					flag = false;
			}
			if (flag)
			{
				use[i] = 1;
				ptr[n] = i + 1;
				queen(n + 1);
				use[i] = 0;
			}
		}
	}
}

vector<vector<string>> solveNQueens(int n)
{
	use.resize(n);
	ptr.resize(n);

	number = n;
	queen(0);
	
	return num;
}

vector<string> num;
vector<int> use;
vector<char> ptr;
map<string, int> m;
void dps(string s, int n)
{
	if (n == s.size())
	{
		string a;
		for (auto ch : ptr)
		{
			a += ch;
		}
		if (m[a] == 1)
		{
			num.resize(num.size());
			return;
		}
		else
			m[a]++;
		num.resize(num.size() + 1);
		num[num.size() - 1] = a;
		return;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (use[i] == 0)
		{
			use[i] = 1;
			ptr[n] = s[i];
			dps(s, n + 1);
			use[i] = 0;
		}
	}
}

vector<string> permutation(string S)
{
	ptr.resize(S.size());
	use.resize(S.size());
	dps(S, 0);
	
	return num;
}



vector<string> permutation(string S) 
{
	ptr.resize(S.size());
	use.resize(S.size());
	dps(S,0);
	auto it = num.begin();
	num.erase(it);
	return num;
}
*/


/*
vector<string> arr;
vector<int> use;
vector<char> kuohao = {'(',')'};
unordered_map<string, int> m;
string s;


bool isgood(string ptr)
{
	int count = 0;
	for (int i = 0; i < ptr.size(); i++)
	{
		if (ptr[i] == '(')
			count++;
		if (ptr[i] == ')')
			count--;
		if (count < 0)
			return true;
	}
	return false;
}

void dps(int n,int max)
{
	if (n == max)
	{
		cout << s << endl;
		if (m[s] == 0 && !isgood(s) && s[max - 1] != '(')
		{
			
			m[s]++;
			arr.push_back(s);
		}
		//cout << s << endl;
		return;
	}
	for (int i = 0; i < max; i++)
	{
		if (use[i] == 0)
		{
			bool flag = true;
			if (s[0] == ')' )
				flag = false;
			if (flag)
			{
				use[i] = 1;
				s[n] = kuohao[i % 2];
				dps(n + 1, max);
				use[i] = 0;
			}

		}
	}
}

vector<string> generateParenthesis(int n) {
	use.resize(n*2);
	s.resize(n * 2);
	dps(0,n*2);
	return arr;
}

int main()
{
	generateParenthesis(3);
	system("pause");
	return 0;
}

*/

vector<string> arr;

bool isgood(string ptr)
{
	int count = 0;
	for (int i = 0; i < ptr.size(); i++)
	{
		if (ptr[i] == '(')
			count++;
		if (ptr[i] == ')')
			count--;
		if (count < 0)
			return true;
	}
	return false;
}

bool judge(string s, int start, int end)
{
	for (int i = start; i < end; ++i) 
	{
		if (s[i] == s[end]) 
			return true;
	}
	return false;
}

void dps(string s, int n)
{
	if (n == s.size())
	{
		arr.push_back(s);
		return;
	}

	for (int i = n; i < s.size(); i++)
	{
		if (judge(s, n, i) ||  isgood(s))	continue;
		swap(s[n], s[i]);
		dps(s,n+1);
		swap(s[i], s[n]);
	}
}

vector<string> generateParenthesis(int n) 
{
	string s;
	for (int i = 0; i < n; i++)
	{
		s += ('(');
		s += (')');
	}
	dps(s, 0);
	return arr;
}

int main()
{
	generateParenthesis(4);
	system("pause");
	return 0;
}