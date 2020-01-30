#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int myAtoi(string str) 
{
	string p;
	string::iterator it;

	int ans = 0, flag = 0, count = 0;
	for (it = str.begin(); it < str.end(); it++)
	if (*it == ' ')
		continue;
	else
		break;
	for (; it < str.end(); it++)
	{
		if (*it =='-' || *it == '+' ||(*it >= '0' && *it <= '9'))
		{
			if (*it == '-')
			{
				if (p.size() != 0)
					break;
				count++;
				flag = 1;
				continue;
			}
			if (*it == '+')
			{
				if (p.size() != 0)
					break;
				count++;
				continue;
			}
			p.push_back(*it);
			continue;
		}
		else
			break;
	}
	if (count > 1)
		return 0;
	it = p.begin();
	while (it<p.end())
	{
		/*ÓëINT_MAX/10±È½Ï*/
		if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && ((*it) - '0')> 7)){
			return flag ? INT_MIN : INT_MAX;
		}
		ans = ans * 10 + ((*it) - '0');
		it++;
	}
	return flag ? -ans : ans;
}

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> str;
	vector<int>::iterator it = find(nums.begin(), nums.end(), target);
	if (!(it < nums.end()))
	{
		str.push_back(-1);
		str.push_back(-1);
	}
	else
	{
		int i = distance(nums.begin(), it);
		str.push_back(i);
		while (i + 1 < nums.size())
		{
			if (nums[i] != nums[i + 1])
				break;
			i++;
		}
		str.push_back(i);
	}
	return str;
}

int main()
{
	cout << myAtoi("   10-42") << endl;
	//vector<int> num = { 1 };
	//for (auto const &ch : searchRange(num, 1))
	//{
	//	cout << ch << ' ';
	//}
	system("pause");
	return 0;
}