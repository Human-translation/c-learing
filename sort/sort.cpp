#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<int> a;



void maopao(vector<int> &a)
{
	int count = 0;
	bool flag = false;
	for (int i = 0; i < a.size(); i++)
	{
		flag = true;
		for (int j = 1; j < a.size() - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				flag = false;
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;

			}
			count++;
		}
		if (flag)
			break;
	}
	cout << count << endl;
}

void zhicha(vector<int> &a)
{
	for (int i = 1; i < a.size(); i++)
	{
		int j = i;
		int tmp = a[i];
		while (j > 0 && tmp < a[j - 1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
}

void xuanze(vector<int> &a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int tmp = a[min];
			a[min] = a[i];
			a[i] = tmp;
		}
	}
}

void xier(vector<int> &a)
{
	int num = a.size() / 2;
	while (num >= 1)
	{
		for (int i = num; i < a.size(); i++)
		{
			int j = i;
			int tmp = a[i];
			while (j >= num && tmp < a[j - num])
			{
				a[j] = a[j - num];
				j -= num;
			}
			a[j] = tmp;
		}
		num = num >> 1;
	}
}

int sort(vector<int> &a, int begin, int end)
{
	int tmp = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= tmp)
		{
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= tmp)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = tmp;
	return begin;
}

void kuaisu(vector<int> &a, int begin, int end)
{
	if (end - begin > 7)
	{
		int k = sort(a, begin, end);
		kuaisu(a, begin, k - 1);
		kuaisu(a, k + 1, end);
	}
	else
	{
		zhicha(a);
	}
}

void merge_sort(vector<int> &a, int begin, int mid, int end)
{
	vector<int> b;
	for (int i = begin; i <= end; i++)
	{
		b.push_back(a[i]);
	}

	int firsta = begin;
	int firstb = mid + 1;

	for (int i = begin; i <= end; i++)
	{
		if (firsta > mid)
		{
			a[i] = b[firstb - begin];
			firstb++;
		}
		else if (firstb > end)
		{
			a[i] = b[firsta - begin];
			firsta++;
		}
		else if (b[firsta - begin] > b[firstb - begin])
		{
			a[i] = b[firstb - begin];
			firstb++;
		}
		else
		{
			a[i] = b[firsta - begin];
			firsta++;
		}
	}
}

void guibing(vector<int> &a, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	guibing(a, begin, mid);
	guibing(a, mid + 1, end);
	merge_sort(a, begin, mid, end);
}

void xier2(vector<int> &arr)
{
	int num = arr.size() / 2;
	while (num >= 1)
	{
		for (int i = num; i < arr.size(); i++)
		{
			int j = i;
			int tmp = arr[i];
			while (j >= num && tmp < arr[j - num])
			{
				arr[j] = arr[j - num];
				j -= num;
			}
			arr[j] = tmp;
		}
		num = num >> 1;
	}
}
int main()
{
	vector<int> a{ 7,3,5,9,1,6,2,4 };
	//maopao(a);
	//zhicha(a);
	//xuanze(a);
	xier2(a);
	//kuaisu(a, 0, a.size()-1);
	//guibing(a,0,a.size()-1);

	for (auto ch : a)
	{
		cout << ch << endl;
	}
	return 0;
}


