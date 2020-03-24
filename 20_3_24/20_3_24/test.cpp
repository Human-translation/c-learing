#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <unordered_map>
#include <string>
using namespace std;

int countPrimes(int n)
{
	if (n == 0 || n == 1)
		return 0;
	int *isPrime = (int*)malloc(sizeof(int) * n);
	memset(isPrime, 0, sizeof(int) * n);
	int i, j, cnt = 0;
	for (i = 2; i < n; i++) {
		if (isPrime[i] == 0) {
			cnt++;
			for (j = i + i; j < n; j += i) {  //É¸È¥iµÄ±¶Êý
				isPrime[j] = 1;
			}
		}
	}
	return cnt;
}

int romanToInt(string s) {
	unordered_map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		cout << m[s[i]] << ' ' << m[s[i + 1]] << endl;
		if (m[s[i]] < m[s[i + 1]])
		{
			num -= m[s[i]];
			continue;
		}
		num += m[s[i]];
	}
	return num;
}


int main()
{
	/*
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int x = rand()%;
	
		cout << x << endl;
	}
	*/
	string s = { "MMMDCCCLXXXVIII" };
	cout << romanToInt(s) << endl;
	system("pause");
	return 0;
}