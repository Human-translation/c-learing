#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) 
{
	int i = 0, j = nums.size();
	int num = 0;
	for (; i < j;i++,j--)
	{
		int max = nums[i];
		int min = nums[i];
		for (int k = i; k < j; k++)
		{
			if (nums[k] > max)
				max = nums[k];
			if (nums[k] < min)
				min = nums[k];
		}
		if (nums[i] != min && nums[j - 1] != max)
		{
			num = j-i;
			break;
		}
		else if (nums[i] != min)
			i--;
		else if (nums[j - 1] != max)
			j++;
	}
	return num;
}

int evalRPN(vector<string>& tokens) 
{
	int num = 0;
	stack<string> mystack;
	for (int i = 0; i < tokens.size(); i++)
	{

	}
}

int main()
{
	//vector<int> num = {  15 };
	//cout << findUnsortedSubarray(num) << endl;

	vector<string> num = { "2", "1", "+", "3", "*" };
	cout << evalRPN(num) << endl;
	system("pause");
	return 0;
}