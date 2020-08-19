#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int run(int num)
{
	int count = 0;
	vector<int> arr(num + 1);
	for (int i = 1; i <= num; i++)
	{
		for (int j = i; j <= num; j += j)
		{
			arr[j]++;
		}
	}
	for (auto ch : arr)
	{
		if (ch % 2 == 1)
			count++;
	}
	return count;
}

int main()
{
	int num;
	while(cin >> num)
	cout<<run(num)<<endl;
	return 0;
}