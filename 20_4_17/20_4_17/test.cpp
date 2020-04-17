#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> m;
void fanzhuan(vector<int>& arr, int r)
{
	int left = 0;
	int right = r - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

bool judge(vector<int>& A)
{
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i - 1] > A[i])
			return false;
	}
	return true;
}

int MyMax(vector<int>& arr)
{
	int max = 0;
	int zuobiao = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max && m[arr[i] == 0])
		{
			max = arr[i];
			zuobiao = i;
		}
	}
	m[max]++;
	return zuobiao + 1;
}

vector<int> pancakeSort(vector<int>& A)
{
	vector<int> arr;
	int weizhi = A.size();
	if (judge(A))
		return arr;
	for (int i = 0; i < A.size(); i++)
	{
		int zuobiao = MyMax(A);
		fanzhuan(A, zuobiao);
		arr.push_back(zuobiao);
		if (judge(A))
			return arr;
		fanzhuan(A, weizhi);
		arr.push_back(weizhi);
		weizhi--;
		if (judge(A))
			return arr;
	}
	return arr;
}

int main()
{
	vector<int> a = {3,2,4,1};
	pancakeSort(a);
	return 0;
}