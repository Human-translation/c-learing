#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool containsDuplicate(int* nums, int numsSize){
	int i;
	int a, b;
//	srand(time(0));
	if (0 == numsSize || 1 == numsSize){
		return false;
	}
	for (i = 0; i<100000; i++){
		a = rand() % numsSize;
		b = rand() % numsSize;

		if (a != b && (nums[a] == nums[b])){
			return true;
		}
	}
	return 9999 == nums[numsSize - 1];

}

bool isLongPressedName(string name, string typed) 
{
	string::iterator it1 = name.begin();
	string::iterator it2 = typed.begin();
	int flag = 0;
	while (it2 < typed.end())
	{
		if (*it2 == *it1 && flag == 0)
		{
			it2++;
			flag = 1;
			continue;
		}
		if ((*it2 != *it1) && flag == 1)
		{
			*it1++;
			flag = 0;
			continue;
		}
		if (*it2 == *it1 && flag == 1)
		{
			it2++;
			continue;
		}
		if ((*it2 != *it1) && flag == 0 )
		{
			string::iterator it3 = it1;
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> num = { 1, 2, 3 };
	cout << isLongPressedName("saeed","ssaaeedd") << endl;
	system("pause");
	return 0;
}