#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;


int compress(vector<char>& chars) {
	int n = chars.size();
	int cur = 0;
	for (int i = 0, j = 0; i < n; j = i) {
		while (i < n && chars[i] == chars[j]) {
			i++;
		}
		chars[cur++] = chars[j];
		if (i - j == 1) {
			continue;
		}
		string s = to_string(i - j);
		for (int t = 0; t < s.size(); t++) {
			chars[cur++] = s[t];
		}
	}
	return cur;
}

bool isPalindrome(string s) 
{
	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		if (!((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= '0' && s[left] <= '9')))
		{
			left++;
			continue;
		}
		if (!((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= '0' && s[right] <= '9')))
		{
			right--;
			continue;
		}
		if (s[left] == s[right] || s[left] == s[right] + 32 || s[left] == s[right] - 32)
		{
			if (s[left] >= '0'&&s[left] <= '9' && s[left] != s[right])
				return 0;
			left++;
			right--;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	//vector<char> num = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	//cout << compress(num) << endl;
	//for (auto const &ch : num)
	//	cout << ch << ' ';
	cout << isPalindrome("0P0") << endl;
	system("pause");
	return 0;
}