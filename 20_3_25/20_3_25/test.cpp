#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;


vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> num;
	if (numRows == 0)
		return num;
	num.resize(numRows);
	for (int i = 0; i < numRows; i++)
	{
		//num[i].resize(i+1);
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				num[i].push_back(1);
				continue;
			}
			num[i].push_back(num[i-1][j]+num[i-1][j-1]);
		}
	}
	return num;
}

	int climbStairs(int n) 
	{
		int dp_i_1 = 1;
		int dp_i_2 = 2;
		int dp_i = dp_i_1;
		for (int i = 2; i < n; i++)
		{
			dp_i = dp_i_1 + dp_i_2;
			dp_i_1 = dp_i_2;
			dp_i_2 = dp_i;
		}
		return dp_i_1;
	}


	int maxProfit(vector<int>& prices) 
	{

		int dp_i_0 = 0;
		int dp_i_1 = -prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			dp_i_0 = max(dp_i_0,dp_i_1+prices[i]);
			dp_i_1 = max(dp_i_1, -prices[i]);
		}
		return dp_i_0;
	}

	int maxSubArray(vector<int>& nums) 
	{
		vector<int> dp;
		if (nums.empty())
			return 0;
		dp.resize(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0)
			{
				dp[i] = nums[i];
				continue;
			}
			dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		}
		int max = dp[0];
		for (auto ch : dp)
			if (ch > max)
				max = ch;
		return max;
	}

	string longestCommonPrefix(vector<string>& strs) 
	{
		string arr;
		if (!strs.size())
			return arr;
		int i = 0, min = strs[0].size();
		for (int j = 1; j < strs.size(); j++)
			if (strs[j].size() < min)
				min = strs[j].size();
		for (; i < min; i++)
		{
			int flag = 0;
			for (int m = 1; m < strs.size(); m++)
			{
				if (strs[m - 1][i] != strs[m][i])
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		return strs[0].substr(0, i);
	}


int main()
{
	string s = { "sdfghj" };
	string b = s.substr(0, 3);
	vector<string> num;
	num.push_back("aab");
	num.push_back("ab");
	num.push_back("b");
	cout<<longestCommonPrefix(num);

	system("pause");
	return 0;
}