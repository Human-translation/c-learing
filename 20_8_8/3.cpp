//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//int run(vector<int> &arr)
//{
//	vector<int> brr;
//	int max = 0;
//	bool flag = true;
//	while (flag)
//	{	
//		flag = false;
//		for (int i = 0; i < arr.size(); i++)
//		{
//			if (!brr.size())
//			{
//				brr.push_back(arr[i]);
//			}
//			else if(arr[i] == brr[brr.size()-1])
//			{
//				brr[brr.size() - 1]++;
//				if(max < brr[brr.size() - 1])
//					max = brr[brr.size() - 1];
//				flag = true;
//			}
//			else
//			{
//				brr.push_back(arr[i]);
//			}
//		}
//		arr = brr;
//		while (brr.size())
//		{
//			brr.pop_back();
//		}
//	}
//
//	return max;
//}
//
//int main()
//{
//	int num;
//	int num1;
//	
//	while (cin >> num)
//	{
//		vector<int> arr;
//		for (int i = 0; i < num; i++)
//		{
//			cin >> num1;
//			arr.push_back(num1);
//		}
//		cout << run(arr) << endl;
//	}
//	return 0;
//}