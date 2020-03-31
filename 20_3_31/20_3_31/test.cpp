#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//vector<string> arr;
//unordered_map<string, int> m;
//void dps(string s, int count)
//{
//	if (count == s.size())
//	{
//		m[s]++;
//		arr.push_back(s);
//		return;
//	}
//
//	for (int i = count; i < s.size(); i++)
//	{
//		if (m[s] != 0)
//			continue;
//		if (s[i] >= 'a' && s[i] <= 'z')
//		{
//
//			s[i] -= 32;
//			dps(s, count + 1);
//			s[i] += 32;
//		}
//		if (s[i] >= 'A' && s[i] <= 'Z')
//		{
//
//			s[i] += 32;
//			dps(s, count + 1);
//			s[i] -= 32;
//		}
//
//		dps(s, count + 1);
//	}
//}
//
//vector<string> letterCasePermutation(string S) 
//{
//	vector<string> result{ S };
//	dps(S, 0);
//	return arr;
//}

//vector<string> letterCasePermutation(string S) {
//	vector<string> result{ S };
//	for (int i = 0; i < S.size(); i++) {
//		if (isupper(S[i])) {
//			int size = result.size();
//			for (int j = 0; j < size; j++) {
//				string temp = result[j];
//				temp[i] = tolower(temp[i]);
//				result.emplace_back(temp);
//			}
//		}
//		else if (islower(S[i])) {
//			int size = result.size();
//			for (int j = 0; j < size; j++) {
//				string temp = result[j];
//				temp[i] = toupper(temp[i]);
//				result.emplace_back(temp);
//			}
//		}
//	}
//	return result;
//}
//
//vector<int> nums = { 1,2,4,8,1,2,4,8,16,32 };
//vector<int> used = { 0,0,0,0,0,0,0,0,0,0 };
//vector<string> arr;
//unordered_map<int, int> m;
//string MyAdd(int hour, int min)
//{
//	char buffer[6];
//	sprintf(buffer, "%d:%.2d", hour, min);
//	string s(buffer);
//	cout << s << endl;
//	return s;
//}
//
//int val(int n)
//{
//	if (used[n] == 0)
//		return 0;
//	return nums[n];
//}
//
//void dps(int count,int num)
//{
//	if (count == num)
//	{
//		int hour = val(1) + val(2) + val(3) + val(0);
//		int min = val(4) + val(5) + val(6) + val(7) + val(8) + val(9);
//		if (hour > 11 || min > 59)	return;
//		if (m[hour * 100 + min] == 0)
//		{
//			arr.push_back(MyAdd(hour, min));
//			m[hour * 100 + min]++;
//		}
//		return;
//	}
//	else
//	{
//		int max = -1;
//		for (int j = 0; j <= nums.size(); j++)
//		{
//			if (used[j] == 1)
//				max = j;
//		}
//		for (int i = 0; i <= nums.size(); i++)
//		{
//			used[i] = 1;
//			if(i > max)
//				dps(count + 1, num);
//			used[i] = 0;
//		}
//	}
//
//}
//
//vector<string> readBinaryWatch(int num) 
//{
//	dps(0,num);
//	return arr;
//}

vector<vector<int>> arr;
vector<int> used;
vector<int> str;
unordered_map<string, int> m;

string change(vector<int> str)
{
	string ptr;
	for (int i = 0; i < str.size(); i++)
	{
		while (str[i])
		{
			ptr += str[i] % 10;
			str[i] /= 10;
		}
	}
	return ptr;
}

void dps(vector<int>& nums,int count)
{
	if (count > 0 && count <= nums.size())
	{
		vector<int> str1(str);
		sort(str1.begin(), str1.end());
		string a = change(str1);
		if (m[a] == 0)
		{
			arr.resize(arr.size() + 1);
			for (auto ch : str1)
			{
				arr[arr.size() - 1].push_back(ch);
			}
			m[a]++;
		}
	}

	for (int i = count; i < nums.size(); i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			str.push_back(nums[i]);
			dps(nums, count + 1);
			str.pop_back();
			used[i] = 0;
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) 
{
	used.resize(nums.size());
	dps(nums, 0);
	arr.resize(arr.size() + 1);
	return arr;
}

int main()
{
	vector<int> num = { 0 };
	subsets(num);
	//vector<int> ivec;
	//ivec.emplace_back(1);
	//ivec.emplace_back(ivec.back());
	//for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
	//	cout << *it << " ";
	//cout << endl;
	system("pause");
	return 0;
}


//["0:03", "0:05", "0:06", "0:09", "0:10", "0:12", "0:17", "0:18", "0:20", "0:24", "0:33", "0:34", "0:36", "0:40", "0:48", "1:01", "1:02", "1:04", "1:08", "1:16", "1:32", "2:01", "2:02", "2:04", "2:08", "2:16", "2:32", "3:00", "4:01", "4:02", "4:04", "4:08", "4:16", "4:32", "5:00", "6:00", "8:01", "8:02", "8:04", "8:08", "8:16", "8:32", "9:00", "10:00"]