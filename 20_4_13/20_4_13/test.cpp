#include <iostream>
#include <vector>
using namespace std;

vector<int> monday = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int rili[8000][13][32];
enum week
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
}Week;

bool runnian(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void AddDay(int& year, int& mon, int& day)
{
	day++;
	int MONDAY = monday[mon - 1];
	if (runnian(year) == 1 && mon == 2)
	{
		MONDAY++;
	}

	if (day > MONDAY)
	{
		day = 1;
		mon++;
	}

	if (mon == 13)
	{
		mon = 1;
		year++;
	}
}

void chushihua()
{
	int year = 0, mon = 1, day = 1;
	Week = Saturday;
	rili[year][mon][day] = Week;
	while (year != 7999 || mon != 12 || day != 31)
	{
		rili[year][mon][day] = Week;
		Week = (week)((Week + 1) % 7);
		AddDay(year, mon, day);
	}
}

void printyear(int year, int mon, int week, int day)
{
	int i = 1;
	for (; rili[year][mon][i] != day; i++);
	i += (week - 1) * 7;
	cout << year + 2000;
	if (mon >= 10)
		cout << " - " << mon;
	else
		cout << " - 0" << mon;
	if (i >= 10)
		cout << " - " << i << endl;
	else
		cout << " - 0" << i << endl;
}

void printyear2(int year, int mon, int day)
{
	int i = 31;
	while (rili[year][mon][i] != day)
	{
		i--;
	}
	cout << year + 2000 << " - 0" << mon << " - " << i << endl;
}

void run(int nianfen)
{
	cout << nianfen << " - 01 - 01" << endl;
	printyear(nianfen - 2000, 1, 3, 1);
	printyear(nianfen - 2000, 2, 3, 1);
	printyear2(nianfen - 2000, 5, 1);
	cout << nianfen << " - 07 - 04" << endl;
	printyear(nianfen - 2000, 9, 1, 1);
	printyear(nianfen - 2000, 11, 4, 4);
	cout << nianfen << " - 12 - 25";

}

int main()
{
	chushihua();
	int nianfen;
	vector<int> arr;
	while (cin >> nianfen)
		arr.push_back(nianfen);
	for (int i = 0; i < arr.size(); i++)
	{
		run(arr[i]);
		if (i != arr.size()-1)
			cout << endl;
	}
	return 0;
}






