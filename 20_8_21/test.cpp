#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void jisuan(vector<int> &arr, string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '/')
		{
			num *= 10;
			num += s[i] - '0';
		}
		else
		{
			arr.push_back(num);
			num = 0;
		}
	}
	arr.push_back(num);
}

void tongfen(vector<int> &arr1, vector<int> &arr2)
{
	if (arr1[1] != arr2[1])
	{
		int tmp1 = arr1[1];
		int tmp2 = arr2[1];
		arr1[0] *= tmp2;
		arr1[1] *= tmp2;
		arr2[0] *= tmp1;
		arr2[1] *= tmp1;
	}
}

void huajian(vector<int> &arr)
{
	int i = 2;
	bool flag = false;
	if (arr[0] < 0)
	{
		arr[0] *= -1;
		flag = true;
	}
	while (i <= arr[0])
	{
		if (arr[0] % i == 0 && arr[1] % i == 0)
		{
			arr[0] /= i;
			arr[1] /= i;
			i = 2;
			continue;
		}
		i++;
	}
	if (arr[0] % arr[1] == 0)
	{
		arr[0] /= arr[1];
		arr[1] = 0;
	}
	if (flag)
		arr[0] *= -1;
}

void run(string &s1, string &s2, string &s3)
{
	vector<int> arr1;
	vector<int> arr2;
	vector<int> arr3(2);
	jisuan(arr1, s1);
	jisuan(arr2, s3);
	tongfen(arr1, arr2);

	if (s2[0] == '+')
	{
		arr3[0] = arr1[0] + arr2[0];
		arr3[1] = arr1[1];
	}
	else if (s2[0] == '-')
	{
		arr3[0] = arr1[0] - arr2[0];
		arr3[1] = arr1[1];
	}
	else if (s2[0] == '*')
	{
		arr3[0] = arr1[0] * arr2[0];
		arr3[1] = arr1[1] * arr2[1];
	}
	else if (s2[0] == '/')
	{
		arr3[0] = arr1[0] * arr2[1];
		arr3[1] = arr1[1] * arr2[0];
	}

	huajian(arr3);
	if (arr3[1] != 0)
		cout << arr3[0] << '/' << arr3[1] << endl;
	else
		cout << arr3[0] << endl;
}

int main()
{
	string s1, s2, s3;
	while(cin >> s1>>s2>>s3)
	run(s1, s2, s3);
	return 0;
}