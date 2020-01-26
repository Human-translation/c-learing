#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) 
{
	queue<int> jique;
	queue<int> ouque;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] % 2 == 0)
		{
			ouque.push(A[i]);
		}
		else
		{
			jique.push(A[i]);
		}
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (ouque.empty() == 0)
		{
			A[i] = ouque.front();
			ouque.pop();
		}
		else
		{
			A[i] = jique.front();
			jique.pop();
		}
	}
	return A;
}

int pivotIndex(vector<int>& nums) 
{
	int sum = 0;
	int	left = 0;
	for (auto const &ch : nums)
	{
		sum += ch;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		left = 0;
		for (int j = 0; j < i; j++)
		{
			left += nums[j];
		}
		if (left * 2 == sum - nums[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	vector<int> num = { 2, 1,1, 0, 4 };
	//for (auto const &ch : sortArrayByParity(num))
	//{
	//	cout << ch << ' ';
	//}
	cout << pivotIndex(num) << endl;
	system("pause");
	return 0;
}