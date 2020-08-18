#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<long long> arr{ 0,1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111 ,11111111111,111111111111,1111111111111,11111111111111};

int run(int num)
{
	int i = 1;
	for (; i < arr.size(); i++)
	{
		if (arr[i] % num == 0)
		{
			return i;
		}
	}
	

}

int main()
{
	int num;
	while(cin >> num)
	cout<<run(num)<<endl;
	return 0;
}