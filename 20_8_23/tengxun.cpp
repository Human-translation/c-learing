#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

//
//int judge(string arr)
//{
//	int begin = 0, end = arr.size() - 1;
//	int i = 0, j = arr.size() - 1;
//	while (i < j)
//	{
//		if (arr[i] != arr[j])
//		{
//			string brr = arr;
//			string crr = arr;
//			for (int count = 0; count <= i - begin; count++)
//			{
//				brr.pop_back();
//				crr.erase(crr.begin());
//			}
//			return min(judge(brr) +1+ i-begin, judge(crr) +1+ i-begin);
//		}
//		i++;
//		j--;
//	}
//	return 1;
//}
//
//void run(string s, int begin, int end)
//{
//	string arr;
//	for (int i = begin; i <= end; i++)
//	{
//		arr += s[i];
//	}
//	cout << judge(arr) << endl;
//}
//
//int main()
//{
//	string s;
//	int num1,num2,num3;
//	cin >> s >> num1;
//	for (int i = 0; i < num1; i++)
//	{
//		cin >> num2>>num3;
//		run(s, num2 - 1, num3 - 1);
//	}
//	
//	return 0;
//}
//
//string arr;
//unordered_set<string> set;
//vector<string> str;
//unordered_map<char, int> map;
//void run(string s)
//{
//	for (int count = 1; count <= s.size(); count++)
//	{
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = 0; j < count; j++)
//			{
//				if (i + j >= s.size())
//				{
//					arr.clear();
//					break;
//				}
//					
//				arr += s[i+j];
//			}
//			if (set.count(arr) == 0)
//			{
//				set.insert(arr);
//				str.push_back(arr);
//				arr.clear();
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	string s;
//	int num;
//	cin >> s>>num;
//	for (auto ch : s)
//	{
//		map[ch]++;
//	}
//	run(s);
//	
//	
//	sort(str.begin(), str.end());
//	cout << str[num] << endl;
//	
//	return 0;
//}


int wei(int num)
{
	int count = 0;
	while (num)
	{
		count += num % 10;
		num /= 10;
	}
	return count;
}

void run(int num)
{
	int max = 0;
	int count = 0;
	for (int i = 9; i < num; i+=10)
	{
		count = 0;
		count += wei(num - i);
		count += wei(i);
		if (count > max)
		{
			max = count;
		}
	}
	cout << max << endl;
}

int main()
{
	int num1, num2;
	cin >> num1;
	while (cin >> num2)
	{
		run(num2);
	}
	return 0;
}