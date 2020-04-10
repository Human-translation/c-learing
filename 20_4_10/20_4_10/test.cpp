/*
#include <iostream>
#include <vector>
using namespace std;



void run(int num, vector<int>& arr)
{
	int count = 0;
	while (arr.size() != 0)
	{
		auto it = arr.begin();
		it = find(++it,arr.end(),arr[0]);
		count += distance(arr.begin(), it )-1;
		arr.erase(it);
		arr.erase(arr.begin());
	}
}

int main()
{
	vector<int> arr = { 1,1,2,2 };
	run(4, arr);
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	int num;
	while (cin >> num)
	{
		int a;
		for (int i = 0; i < num * 2; i++)
		{
			cin >> a;
			arr.push_back(a);
		}
		int count = 0;
		while (arr.size() != 0)
		{
			auto it = arr.begin();
			it = find(++it, arr.end(), arr[0]);
			count += distance(arr.begin(), it) - 1;
			arr.erase(it);
			arr.erase(arr.begin());
		}
		cout << count << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> sushu = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
  53,59,61,67,71,73,79,83,89,97,
  101,103,107,109,113,127,131,137,139,149,
  151,157,163,167,173,179,181,191,193,197,199,
  211,223,227,229,233,239,241,
  251,257,263,269,271,277,281,283,293,
  307,311,313,317,331,337,347,349,
  353,359,367,373,379,383,389,397,
  401,409,419,421,431,433,439,443,449,
  457,461,463,467,479,487,491,499,
  503,509,521,523,541,547,
  557,563,569,571,577,587,593,599,
  601,607,613,617,619,631,641,643,647,
  653,659,661,673,677,683,691,
  701,709,719,727,733,739,743,
  751,757,761,769,773,787,797,
  809,811,821,823,827,829,839,
  853,857,859,863,877,881,883,887,
  907,911,919,929,937,941,947,
  953,967,971,977,983,991,997 };

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int left = 0;
		int right = sushu.size() - 1;
		while (left <= right)
		{
			if (sushu[left] + sushu[right] > n)
			{
				right--;
			}
			if (sushu[left] + sushu[right] < n)
			{
				left++;
			}
			if (sushu[left] + sushu[right] == n)
			{
				left++;
				right--;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = { 9 ,6, 4, 2, 1, 3, 5, 7, 0, 1, 8 };
	int addnum = (arr.size() - 1)*(arr.size()-2) / 2 * -1;
	auto it = arr.rbegin();

	cout << addnum << endl;
	return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num, hour, min, latetime;
	int latemin;
	vector<int> arr;
	cin >> num;
	for(int i=0;i<num;i++)
	{
		cin >> hour >> min;
		arr.push_back(hour * 60 + min);
	}
	sort(arr.begin(), arr.end());
	cin >> latetime >> hour >> min;
	latemin = hour * 60 + min - latetime;
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		if (*it < latemin)
		{
			cout << *it << endl;
			cout << *it / 60 << ' ' << *it % 60 << endl;
			break;
		}
	}
	system("pause");
	return 0;
}