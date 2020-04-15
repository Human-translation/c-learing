#include <iostream>
#include <vector>
using namespace std;

int paixu(vector<int>& arr, int left, int right)
{
	int max = INT_MIN, min = INT_MAX;
	int tmp[3] = { arr[left],arr[(left + right) / 2],arr[right] };
	if (right - left >= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			if (max < tmp[i])	max = tmp[i];
			if (min > tmp[i])	min = tmp[i];
		}
		for (int i = 0; i < 3; i++)
		{
			if (tmp[i] == tmp[0] + tmp[1] + tmp[2] - max - min)
			{
				if (i == 1)
				{
					arr[(left + right) / 2] = arr[left];
					arr[left] = tmp[i];
					break;
				}
				if (i == 2)
				{
					arr[right] = arr[left];
					arr[left] = tmp[i];
				}
			}
		}
	}
	int num = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= num) --right;
		arr[left] = arr[right];
		while (left < right && arr[left] <= num) ++left;
		arr[right] = arr[left];
	}
	arr[left] = num;
	return left;
}

void quitsort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int pos = paixu(arr,left,right);
		quitsort(arr,left,pos-1);
		quitsort(arr,pos+1,right);
	}
}

int main()
{
	vector<int> arr = { 3,2,1,5,3 };
	quitsort(arr, 0, arr.size() - 1);
	for (auto ch : arr)
	{
		cout << ch << ' ';
	}
	return 0;
}