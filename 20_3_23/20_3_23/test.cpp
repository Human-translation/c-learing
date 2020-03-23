#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
void rotate(vector<vector<int>>& matrix) {
	int left = 0, right = matrix[0].size()-1, up = 0, back = matrix.size()-1;
	for (int i = 0; i < matrix.size()/2; i++)
	{
		for (int j = 0; j < right-left; j++)
		{
			int tmp = matrix[back - j][left];
			matrix[back - j][left] = matrix[back][right - j];
			matrix[back][right - j] = matrix[up + j][right];
			matrix[up + j][right] = matrix[up][left + j];
			matrix[up][left + j] = tmp;
		}
		left++;
		right--;
		up++;
		back--;
	}
}

int main()
{
	vector<vector<int>> num(6);
	num[0].push_back(1);
	num[0].push_back(2);
	num[0].push_back(3);
	num[0].push_back(4);
	num[0].push_back(5);
	num[0].push_back(6);
	num[1].push_back(7);
	num[1].push_back(8);
	num[1].push_back(9);
	num[1].push_back(10);
	num[1].push_back(11);
	num[1].push_back(12);
	num[2].push_back(13);
	num[2].push_back(14);
	num[2].push_back(15);
	num[2].push_back(16);
	num[2].push_back(17);
	num[2].push_back(18);
	num[3].push_back(19);
	num[3].push_back(20);
	num[3].push_back(21);
	num[3].push_back(22);
	num[3].push_back(23);
	num[3].push_back(24);
	num[4].push_back(25);
	num[4].push_back(26);
	num[4].push_back(27);
	num[4].push_back(28);
	num[4].push_back(29);
	num[4].push_back(30);
	num[5].push_back(31);
	num[5].push_back(32);
	num[5].push_back(33);
	num[5].push_back(34);
	num[5].push_back(35);
	num[5].push_back(36);
	rotate(num);
	system("pause");
	return 0;
}


[[2,29,20,26,16,28],
[12,27,9,25,13,21],
[32,33,32,2,28,14],
[13,14,32,27,22,26],
[33,1,20,7,21,7],
[4,24,1,6,32,34]]

*/

void reverseString(vector<char>& s) {
	reverse(s.begin(), s.end());
}

bool isAnagram(string s, string t) {
	unordered_map<int, int> m;
	for (auto ch : s)
		m[ch]++;
	for (auto ch : t)
	{
		m[ch]--;
	}
	for (auto ch : m)
		if (ch.second != 0)
			return false;
	return true;
}


string countAndSay(int n) {

}

int main()
{
	string s1 = { "anagram" };
	string s2 = { "nagaram" };
	for (int i = 1; i < 11; i++)
	{
		cout << countAndSay(i);
		cout << endl;
	}
	
	system("pause");
	return 0;
}