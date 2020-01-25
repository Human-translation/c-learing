#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void sort(vector<int>& a)
{
	for (int i = 0; i<a.size() - 1; i++){
		for (int j = i + 1; j<a.size(); j++){
			if (a[j]<a[i]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

vector<int> sortedSquares(vector<int>& A)
{
	for (auto &ch : A)
	{
		ch = ch * ch;
	}
	sort(A);
	return A;
}

string reverseOnlyLetters(string S) 
{
	stack<char> mystack;
	string::iterator it = S.begin();
	while (it < S.end())
	{
		if ((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z'))
		{
			mystack.push(*it);
		}
		it++;
	}
	it = S.begin();
	while (it < S.end())
	{
		if ((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z'))
		{
			*it = mystack.top();
			mystack.pop();
		}
		it++;
	}
	return S;
}

int main()
{
	//vector<int> num = { -3, -2, -1, 0, 4, 5, 6 };
	//sortedSquares(num);
	//for (auto const &ch : num)
	//{
	//	cout << ch << ' ';
	//}

	
	cout << reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
	system("pause");
	return 0;
}