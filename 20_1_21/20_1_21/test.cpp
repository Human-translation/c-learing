#include <iostream>
#include <vector>
#include <string>
using namespace std;

string toLowerCase(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	return str;
}


void xuanzhuan(vector<int>& nums, int numbegin, int numend)
{
	while (numbegin < numend)
	{
		int num = nums[numbegin];
		nums[numbegin] = nums[numend];
		nums[numend] = num;
		numend--;
		numbegin++;
	}
}

void rotate(vector<int>& nums, int k)
{
	int newk = k % nums.size();
	xuanzhuan(nums, 0, nums.size() - newk - 1);
	xuanzhuan(nums, nums.size() - newk, nums.size() - 1);
	xuanzhuan(nums, 0, nums.size() - 1);
}