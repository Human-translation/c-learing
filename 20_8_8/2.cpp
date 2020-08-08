//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//void run(vector<int> &youhui, vector<int> &jiazhi,vector<int> &jiaoqian,int &yuji,int& shiji)
//{
//	for (int i = 0; i < youhui.size(); i++)
//	{
//		if (jiaoqian[i] < 0)
//			yuji += jiazhi[i];
//		else
//		{
//			yuji += youhui[i];
//			shiji += jiaoqian[i];
//		}
//	}
//}
//
//int main()
//{
//	vector<int> youhui;
//	vector<int> jiazhi;
//	vector<int> jiaoqian;
//	int num;
//	int num1, num2;
//	while (cin >> num)
//	{
//		int yuji=0, shiji=0;
//		for (int i = 0; i < num; i++)
//		{
//			cin >> num1 >> num2;
//			youhui.push_back(num1);
//			jiazhi.push_back(num2);
//			jiaoqian.push_back(num1 - num2);
//
//		}
//		run(youhui, jiazhi, jiaoqian, yuji,shiji);
//		cout << yuji << ' ' << shiji << endl;
//	}
//}