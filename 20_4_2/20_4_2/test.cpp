#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

/*
	0000 1010

int exchangeBits(int num) 
{
	return (num << 1 & 0xAAAAAAAA) | (num >> 1 & 0x55555555);
}


int erfen(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return -1;
	int min = -1;
	int mid = (left + right) / 2;
	if (mid != nums[mid])
	{
		int lef = erfen(nums, left, mid - 1);
		int rig = erfen(nums, mid+1, right);
		if (lef != -1)
			return lef;
		if (rig != -1)
			return rig;
	}
	else
	{
		min = erfen(nums, left, mid - 1);
		if (min == -1)
			return mid;
		else
			return min;
	}
	return -1;
}

int findMagicIndex(vector<int>& nums)
{
	return erfen(nums, 0, nums.size() - 1);
}


void chuli(vector<vector<int>>& arr, vector<vector<int>>& image, int Length, int Width)
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			image[i][j] = arr[i + 1][j + 1];
		}
	}
}

void Change(vector<vector<int>>& arr, vector<vector<int>> image, int sr, int sc, int Length, int Width,int Color,int newColor)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	if (arr[sr][sc] == Color)
		arr[sr][sc] = newColor;
	else
		return;
	if (sr+1<=Length && arr[sr + 1][sc] == Color)
		Change(arr, image, sr+1, sc, Length, Width, Color, newColor);
	if (sr-1 >= 0 && arr[sr - 1][sc] == Color)
		Change(arr, image, sr - 1, sc, Length, Width, Color, newColor);
	if (sc+1<=Width && arr[sr][sc + 1] == Color)
		Change(arr, image, sr, sc + 1, Length, Width, Color, newColor);
	if (sc-1>= 0 && arr[sr][sc - 1] == Color)
		Change(arr, image, sr, sc - 1, Length, Width, Color, newColor);

}

void Init(vector<vector<int>>& arr, vector<vector<int>> image,int Length,int Width)
{
	for (int i = 0; i < Length + 2; i++)
	{
		arr[i].resize(Width + 2);
	}
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			arr[i + 1][j + 1] = image[i][j];
		}
	}
}

void change(vector<vector<int>>& arr, int sr, int sc, int Color, int newColor)
{

	//for (int i = 0; i < arr.size(); i++)
	//{
	//	for (int j = 0; j < arr[0].size(); j++)
	//	{
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	if (arr[sr][sc] == Color)
		arr[sr][sc] = newColor;
	else
		return;
	if (sr + 1 < arr.size() && arr[sr + 1][sc] == Color)
		change(arr, sr + 1, sc, Color, newColor);
	if (sr - 1 >= 0 && arr[sr - 1][sc] == Color)
		change(arr, sr - 1, sc, Color, newColor);
	if (sc + 1 < arr[0].size() && arr[sr][sc + 1] == Color)
		change(arr, sr, sc + 1, Color, newColor);
	if (sc - 1 >= 0 && arr[sr][sc - 1] == Color)
		change(arr, sr, sc - 1, Color, newColor);

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
	int Length = image.size(), Width = image[0].size();
	int Color = image[sr][sc];
	if (Color == newColor)
		return image;
	//vector<vector<int>> arr(Length+2);
	//Init(arr, image, Length, Width);
	//Change(arr, image, sr, sc, Length, Width, Color, newColor);
	//chuli(arr, image, Length, Width);
	change(image, sr, sc, Color, newColor);
	return image;
}

int add(int a, int b) {
	if (b == 0)
		return a;
	int step1 , step2 ;
	do
	{
		step1 = a ^ b;
		step2 = (a & b) << 1;
		a = step1;
		b = step2;
	} while (b != 0);
	return step1;
}



int main()
{
	
	//vector<vector<int>> nums(2);
	//nums[0].push_back(0);
	//nums[0].push_back(1);
	//nums[0].push_back(0);
	//nums[1].push_back(0);
	//nums[1].push_back(0);
	//nums[1].push_back(1);
	//floodFill(nums,0,0,2);

	cout << add(-1, 2);
	system("pause");
	return 0;
}
*/



void Init(vector<vector<int>>& arr, vector<vector<int>> image, int Length, int Width)
{
	for (int i = 0; i < Length + 2; i++)
	{
		arr[i].resize(Width + 2);
	}
}

int MyAdd(vector<vector<int>> num,int i,int j)
{
	int count = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && num[i - 1][j - 1] == 1)
		count++;
	if (i - 1 >= 0 && num[i - 1][j] == 1)
		count++;
	if (i - 1 >= 0 && j + 1 < num[0].size() && num[i - 1][j + 1] == 1)
		count++;
	if (j - 1 >= 0 && num[i][j - 1] == 1)
		count++;
	if (j + 1 < num[0].size() && num[i][j + 1] == 1)
		count++;
	if (i + 1 < num.size() && j - 1 >= 0 && num[i + 1][j - 1] == 1)
		count++;
	if (i + 1 < num.size() && num[i + 1][j] == 1)
		count++;
	if (i + 1 < num.size() && j + 1 < num[0].size() && num[i + 1][j + 1] == 1)
		count++;
	return count;
}

void jishu(vector<vector<int>>& arr, vector<vector<int>> image, int Length, int Width)
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			arr[i + 1][j + 1] = MyAdd(image,i,j);
		}
	}
}

void zhuanhuan(vector<vector<int>>& arr, vector<vector<int>>& image, int Length, int Width)
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (arr[i + 1][j + 1] == 3)
				image[i][j] = 1;
			else if (arr[i + 1][j + 1] < 2 || arr[i + 1][j + 1]>3)
				image[i][j] = 0;
		}
	}
}

void print(vector<vector<int>>& arr, int Length, int Width)
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			cout << ' '<< arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void gameOfLife(vector<vector<int>>& board) 
{
	int Length = board.size();
	int Width = board[0].size();
	while (1)
	{
		vector<vector<int>> arr(Length + 2);
		Init(arr, board, Length, Width);
		jishu(arr, board, Length, Width);
		zhuanhuan(arr, board, Length, Width);
		Sleep(1000);
		system("cls");
		print(board, Length, Width);

	}
}




int main()
{

	vector<vector<int>> nums(4);
	nums[0].push_back(0);
	nums[0].push_back(1);
	nums[0].push_back(0);
	nums[1].push_back(0);
	nums[1].push_back(0);
	nums[1].push_back(1);
	nums[2].push_back(1);
	nums[2].push_back(1);
	nums[2].push_back(1);
	nums[3].push_back(0);
	nums[3].push_back(0);
	nums[3].push_back(0);
	gameOfLife(nums);
	system("pause");
	return 0;
}