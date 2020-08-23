#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void run(vector<vector<int>> &arr, int num)
{
	int i = 1;
	int shang = 0, xia = arr.size() - 1;
	int zuo = 0, you = arr.size() - 1;
	int hang = 0, lie = arr.size() - 1;
	while(i<=num)
	{
		for (hang = shang,lie=you; hang <= xia; hang++)
		{
			arr[hang][lie] = i++;
		}
		you--;

		for (lie = you,hang=xia; lie >= zuo; lie--)
		{
			arr[hang][lie] = i++;
		}
		xia--;

		for (hang = xia,lie = zuo; hang >=shang; hang--)
		{
			arr[hang][lie] = i++;
		}
		zuo++;

		for (lie = zuo,hang=shang; lie <= you ; lie++)
		{
			arr[hang][lie] = i++;
		}
		shang++;
	}

}

//int main()
//{
//	int num;
//	cin >> num;
//	if (num > 20)
//		cout << "error" << endl;
//	else
//	{
//		vector<vector<int>> arr(num);
//		for (int i = 0; i < arr.size(); i++)
//		{
//			arr[i].resize(num);
//		}
//		run(arr, num*num);
//		for (int i = 0; i < arr.size(); i++)
//		{
//			for (int j = 0; j < arr[i].size(); j++)
//			{
//				
//				cout << arr[i][j];
//				if(j!=num-1)
//					cout << "\t";
//			}
//			if(i!=num-1)
//				cout << endl;
//		}
//	}
//		
//	return 0;
//}


