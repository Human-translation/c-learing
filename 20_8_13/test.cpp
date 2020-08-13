#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int GetCoinCount(int N) 
{
	int arr[] = { 1,4,16,64 };
	N = 1024 - N;
	vector<int> dp(N+1,1024);
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] <= i)
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			else
				break;
		}
	}
	return dp[dp.size()-1];
}

int main()
{
	cout << GetCoinCount(200);
}