#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x)
{
	if (x < 0 || (x%10==0 && x!=0))
		return 0;
	int count = 0;
	int y = 0;
	while(x>y)
	{
		y = y * 10 + x % 10;
		x = x / 10;
	}
	return x == y || x == y / 10;
}

bool canConstruct(string ransomNote, string magazine) 
{
	int num[26] = { 0 };
	for (int i = 0; i < magazine.size(); i++)
	{
		num[magazine[i] - 'a']++;
	}
	for (int i = 0; i < ransomNote.size(); i++)
	{
		num[ransomNote[i] - 'a']--;
		if (num[ransomNote[i] - 'a'] == -1)
			return 0;
	}
	return 1;
}

int main()
{
	int x = 120;
	cout << isPalindrome(x) << endl;
//	cout << canConstruct("abcd","ab") << endl;
	system("pause");
	return 0;
}