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


int caculcolumnSize(int n){//�����Ӽ�����Ŀռ䣬��n=6,������110������ռ�return 2
	int count = 0;           //n=2 ,������010������ռ�return 1
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
void getnumformnums(int *nums, int *numout, int n){//��װ�Ӽ�numout��
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
		int columnSizes = caculcolumnSize(i);//�Ӽ���С
		output[i] = (int*)malloc(sizeof(int)*columnSizes);
		getnumformnums(nums, output[i], i);//�����Ӽ�
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