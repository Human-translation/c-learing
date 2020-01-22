#include <iostream>
#include <vector>
#include <string>
using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	int i = 0;
	while (i<nums.size())
	{
		if (nums[i] == val)
		{
			nums.erase(nums.begin()+i);
			continue;
		}
		i++;
	}
	return nums.size();
}

int searchInsert(vector<int>& nums, int target)
{
	if (target <= nums[0])
		return 0;
	else if (target > nums[nums.size() - 1])
		return nums.size();
	else
	{
		int i = 0;
		while (i < nums.size())
		{
			if (nums[i] < target)
			{
				i++;
			}
			else
				return i;
		}
	}
	return 0;
}

int main()
{
	vector<int> num = { 1, 3, 5, 6 };
	int val = 2;
//	removeElement(num, val);
	val = searchInsert(num, val);
	cout << val << endl;
	system("pause");
	return 0;
}