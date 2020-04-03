#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

vector<string> arr;

bool just(string s, int left, int right)
{
	for(int i=left;i<right;i++)
	{
		if (s[i] == s[right])
			return true;
	}
	return false;
}

void dps(string s, int count)
{
	if (count >= s.size())
	{
		cout << s << endl;
		arr.push_back(s);
		return;
	}

	for (int i = count; i < s.size(); i++)
	{
		if (just(s, count, i)) continue;
		//if (s[i] == s[i+1])	continue;
		swap(s[i], s[count]);
		dps(s, count + 1);
		swap(s[count], s[i]);
	}

}


vector<string> permutation(string S) 
{
	sort(S.begin(), S.end());
	dps(S, 0);
	return arr;
}

int main()
{
	permutation("qqe");
	system("pause");
	return 0;
}