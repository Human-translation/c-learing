#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int>num = nums;
	sort(num.begin(), num.end());
	vector<int> str;
	int left = 0;
	int right = num.size() - 1;
	while (left < right)
	{
		if (num[left] + num[right] > target)
		{
			right--;
		}
		if (num[left] + num[right] < target)
		{
			left++;
		}
		if (num[left] + num[right] == target)
		{
			str.push_back(num[left]);
			str.push_back(num[right]);
			break;
		}
	}
	int flag1 = 0, flag2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (str[0] == nums[i] && flag1==0)
		{
			flag1 = 1;
			str[0] = i;
			continue;
		}
		if (str[1] == nums[i] && flag2==0)
		{
			flag2 = 1;
			str[1] = i;
		}
	}
	return str;
}

string addBinary(string a, string b) 
{
	int al = a.size();
	int bl = b.size();
	while (al < bl) 
	{
		a = '0' + a;
		++al;
	}
	while (al > bl)
	{
		b = '0' + b;
		++bl;
	}
	for (int j = a.size() - 1; j > 0; --j) 
	{
		a[j] = a[j] - '0' + b[j];
		if (a[j] >= '2') 
		{
			a[j] = (a[j] - '0') % 2 + '0';
			a[j - 1] = a[j - 1] + 1;
		}
	}
	a[0] = a[0] - '0' + b[0]; 
	if (a[0] >= '2')
	{
		a[0] = (a[0] - '0') % 2 + '0';
		a = '1' + a;
	}
	return a;
}

int main()
{
	//vector<int> num = { 1, 3, 4, 2};
	//int x = 6;
	//for (auto const &ch : twoSum(num,x))
	//{
	//	cout << ch << ' ';
	//}
	cout << addBinary("1010", "1011") << endl;
	system("pause");
	return 0;
}