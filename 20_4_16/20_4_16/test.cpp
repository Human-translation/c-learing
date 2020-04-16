#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
	int len = right - left + 1;
	vector<int> arrl;
	vector<int> arrr;
	for (int i = left; i <= mid; i++)
	{
		arrl.push_back(arr[i]);
	}
	for (int i = mid + 1; i <= right; i++)
	{
		arrr.push_back(arr[i]);
	}
	int m = 0, n = 0;
	int i = left;
	while (i <= right)
	{
		if (arrl[m] <= arrr[n])
		{
			arr[i] = arrl[m];
			m++;
		}
		else if (arrl[m] > arrr[n])
		{
			arr[i] = arrr[n];
			n++;
		}
		i++;
		if (m == arrl.size() || n == arrr.size())
			break;
	}
	while (m != arrl.size())
	{
		arr[i] = arrl[m];
		i++; 
		m++;
	}
	while (n != arrr.size())
	{
		arr[i] = arrr[n];
		i++;
		n++;
	}
}

void MergeSort(vector<int>& arr,int left,int right)
{
	if (left == right)
		return ;
	int mid = (left + right) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int main()
{
	vector<int> arr = { 2,3,5,8,1,4,6,7,9 };
	MergeSort(arr,0,arr.size()-1);
	for (auto ch : arr)
	{
		cout << ch << ' ';
	}
	return 0;
}