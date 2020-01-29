#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	if (n == 0)
		return;
	for (int i = 0; i < n; i++)
	{
		nums1[m + i] = nums2[i];
	}
	sort(nums1.begin(), nums1.end());
}

int lengthOfLastWord(string s) 
{
	if (s.size() == 0)
		return 0;
	while (s[s.size() - 1] == ' ')
	{
		s.pop_back();
	}
	string::reverse_iterator pos = find(s.rbegin(), s.rend(), ' ');
	string::reverse_iterator it = s.rbegin();
	int count = 0;
	while (it < pos)
	{
		count++;
		it++;
	}
	return count;
}

int main()
{
	//vector<int> num1 = {1 ,2,3,0,0,0};
	//vector<int> num2 = { 1, 2, 2 };
	//merge(num1, 3, num2, 3);
	//for (auto const &ch : num1)
	//{
	//	cout << ch << ' ';
	//}
	cout << lengthOfLastWord("a ") << endl;
	system("pause");
	return 0;
}