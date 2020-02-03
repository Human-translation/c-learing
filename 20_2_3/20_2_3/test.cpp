#include <iostream>
#include <vector>
using namespace std;

int ROW(int len)
{
	int i = 0;
	int num = 1;
	while (i < len)
	{
		num *= 2;
		i++;
	}
	return num;
}

vector<vector<int>> subsets(vector<int>& nums) 
{
	vector<vector<int>> num;
	int row = ROW(nums.size());
	int size = row/2;
	int count = 0;
	num.resize(row);
	for (int i = 0; i < num.size()-1;)
	{
		for (int j = 0; j < size; j++)
		{
			num[i++].push_back(nums[count]);
		}
		size /= 2;
		count++;
	}
	return num;
}


int caculcolumnSize(int n){//计算子集所需的空间，如n=6,二进制110，所需空间return 2
	int count = 0;           //n=2 ,二进制010，所需空间return 1
	while (n>0){
		if (((n >> 1) << 1) == n){
			n = n >> 1;
			continue;
		}
		else{
			n = n >> 1;
			count++;
		}
	}
	return count;
}
void getnumformnums(int *nums, int *numout, int n){//组装子集numout。
	int k = 0, count = 0;
	while (n>0){
		if (((n >> 1) << 1) == n){
			n = n >> 1;
		}
		else{
			n = n >> 1;
			numout[k++] = nums[count];
		}
		count++;
	}
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int inputotal = (int)pow(2.0, numsSize);
	int **output = (int**)malloc(sizeof(int*)*inputotal);
	*returnColumnSizes = (int*)malloc(sizeof(int)*inputotal);
	for (int i = 0; i<inputotal; i++){
		int columnSizes = caculcolumnSize(i);//子集大小
		output[i] = (int*)malloc(sizeof(int)*columnSizes);
		getnumformnums(nums, output[i], i);//生成子集
		(*returnColumnSizes)[i] = columnSizes;
	}
	*returnSize = inputotal;
	return output;
}



int main()
{
	vector<int> num = { 1, 2, 3,4 };
	subsets(num);
	system("pause");
	return 0;
}