#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void run(string s)
{
	int max = 0;
	int begin = 0;
	int curnum = 0;
	unordered_map<int, int> map;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
			curnum--;
		else
			curnum++;

		auto ptr = map.find(curnum);
		if (ptr != map.end())
		{
			int num = map[curnum];
			if (i + 1 - num > max)
			{
				max = i + 1 - num;
				begin = num;
			}
		}
		else
		{
			map[curnum] = i + 1;
		}

		if (curnum == 0)
		{
			int num = i + 1;
			if (num > max)
			{
				max = i + 1;
				begin = 0;
			}
		}
	}
}

int main()
{
	run("1010110100");
	return 0;
}



