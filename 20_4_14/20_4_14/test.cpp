#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
/*
vector<int> monday = { 31,28,31,30,31,30,31,31,30,31,30,31 };
vector<int> arr = { 2,3,5,7,11 };

bool runnian(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int yuannian(vector<int> arr, int year, int mon, int day,bool flag)
{
	int daynum = 0;
	if (runnian(year) && mon > 2)
	{
		daynum++;
	}
	for (int i = 0; i < mon-1; i++)
	{
		if (i+1 != 2 && i+1 != 3 && i + 1 != 5 && i + 1 != 7 && i + 1 != 11)
			daynum += monday[i];
		daynum += monday[i];
	}
	if (mon != 2 && mon != 3 && mon != 5 && mon != 7 && mon != 11)
		daynum += day * 2;
	else
		daynum += day;
	if (flag  && (mon != 2 && mon != 3 && mon != 5 && mon != 7 && mon != 11))
		daynum -= 2;
	else if (flag  && (mon == 2 || mon == 3 || mon == 5 || mon == 7 || mon == 11))
		daynum -= 1;
	//cout << daynum << endl;
	if (year != 2000)
	{
		for (int i = 2000; i < year; i++)
		{
			if (runnian(i))
				daynum += 580;
			else
				daynum += 579;
		}
			
	}
	return daynum;
}
//2014 3 12
void jisuan(vector<int> from,vector<int> to,int i)
{
	int fromnum = yuannian(from, from[i], from[i + 1], from[i + 2],1);
	int tonum = yuannian(to, to[i], to[i + 1], to[i + 2],0);

	cout << tonum - fromnum << endl;
}

int main()
{
	int fyear, fmon, fday, tyear, tmon, tday;
	vector<int> From;
	vector<int> To;
	while (cin >> fyear >> fmon >> fday >> tyear >> tmon >> tday)
	{
		From.push_back(fyear);
		From.push_back(fmon);
		From.push_back(fday);
		To.push_back(tyear);
		To.push_back(tmon);
		To.push_back(tday);
	}
	for (int i = 0; i < From.size(); i = i + 3)
	{
		jisuan(From, To, i);
	}
	return 0;
}*/
/*
int main()
{
	int a[5][5];
	int(*p)[4];
	
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}*/

int main() {
	string s;
	cin >> s;
	s += s;
	int len = s.size();
	int res = 0;
	for (int i = 0; i < len; i++) {
		int j = i + 1;
		while (j < len && s[j] != s[j - 1]) {
			j++;
		}
		res = max(res, j - i);
		i = j - 1;
	}
	cout << min(res, len / 2) << endl;
	return 0;
}


