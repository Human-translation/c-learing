#include <iostream>

using namespace std;

int maximum(int a, int b) {
	long k = (((long)a - (long)b) >> 63) & 1;
	return b * k + a * (k ^ 1);
}

int main()
{
	cout<<maximum(-3,2);
	system("pause");
	return 0;
}