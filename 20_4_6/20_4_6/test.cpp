#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> missingTwo(vector<int>& nums) {
	int n = nums.size() + 2;
	long sum = 0;
	for (auto x : nums) sum += x;

	int sumTwo = n * (n + 1) / 2 - sum, limits = sumTwo / 2;
	sum = 0;
	for (auto x : nums)
		if (x <= limits) sum += x; // 两个数不相同那么一个大于，一个小于
	int one = limits * (limits + 1) / 2 - sum;
	return { one, sumTwo - one };
}

int main()
{
	vector<int> arr = {2,3};
	//arr = missingTwo(arr);
	string a = { "asdfghjasdfghsdfvgbhj" };
	vector<string> b;
	b.push_back("sd");
	int num = b[0].size();
	a.erase(1,3);
	cout<<a.find(b[0])<<' '<<a;
	system("pause");
	return 0;
}