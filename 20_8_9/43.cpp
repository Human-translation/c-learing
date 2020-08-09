#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void jishuan(string str1, string str2)
{

}

string fanzhuan(string num)
{
	int left = 0;
	int right = num.size()-1;
	while (left < right)
	{
		char tmp = num[left];
		num[left] = num[right];
		num[right] = tmp;
		left++;
		right--;
	}
	return num;
}

string multiply(string num1, string num2) 
{
	if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0'))
	{
		return "0";
	}

	string str1 = fanzhuan(num1);
	string str2 = fanzhuan(num2);

	jishuan(str1, str2);
	return num1;
}

int main()
{
	cout << multiply("123", "456") << endl;
	return 0;
}