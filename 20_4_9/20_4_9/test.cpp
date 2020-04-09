#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string a = { "aaaa" };
	string b = { "ertyuio" };
	a = b.substr(2, 1);
	cout << a << endl;
	system("pause");
	return 0;
}