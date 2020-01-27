#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int thirdMax(vector<int>& nums) {   // by me
	sort(nums.begin(), nums.end());
	vector<int> newNums(1);
	newNums[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	if ((newNums.back()) != nums[i])
		newNums.push_back(nums[i]);
	if (newNums.size() == 2) return newNums[1];
	else if (newNums.size() == 1) return newNums[0];
	else return newNums[newNums.size() - 3];
}

vector<int> plusOne(vector<int>& digits) 
{
	vector<int>::iterator it = digits.begin();
	digits[digits.size() - 1]++;
	for (int i = 1; i<digits.size(); i++)
	{
		if (digits[digits.size() - i] > 9)
		{
			digits[digits.size() - i] = 0;
			digits[digits.size() - i - 1]++;
		}
	}
	if (digits[0] > 9)
	{
		digits[0] = 0;
		it = digits.insert(it, 1);
	}
	return digits;
}

int main()
{
	//vector<int> num = { 1, 2, -2147483647 };
	//cout << thirdMax(num) << endl;
	vector<int> num = { 9,9 };
	for (auto const &ch : plusOne(num))
	{
		cout << ch << ' ';
	}
	system("pause");
	return 0;
}