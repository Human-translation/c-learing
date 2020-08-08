#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, int> map;
	int num;
	double arr = 0, brr = 0;
	for (int i = 1; i <= 5; i++)
	{
		cin >> num;
		arr += num * i;
		brr += num;
	}
	double crr = arr / brr;
	crr *= 10;
	crr = (int)crr;
	crr /= 10.0;
	if (crr == 1)
	{
		cout << "1.0" << endl;
	}
	else if (crr == 2)
	{
		cout << "1.0" << endl;
	}
	else if (crr == 3)
	{
		cout << "1.0" << endl;
	}
	else if (crr == 4)
	{
		cout << "1.0" << endl;
	}
	else if (crr == 5)
	{
		cout << "1.0" << endl;
	}
	else if (crr > 0)
		cout << crr << endl;
	else
		cout << "0.0" << endl;
	return 0;
}