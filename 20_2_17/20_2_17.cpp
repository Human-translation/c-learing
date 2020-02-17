#include <iostream>
#include <vector>
using namespace std;



void MergeSort(vector<int> &num,int left,int right)
{
    if(left < right) return;
    int mid = (left+right) / 2;
    MergeSort(num,left,mid);
    MergeSort(num,mid+1,right);
//    Merge(num);
}


int main()
{
    vector<int> num = {5, 3, 8, 1, 6, 7, 9 ,42,11,13,10,4};
    //BubbleSort(num);
    //InsertSort(num);
    //SelectSort(num);
    MergeSort(num,0,num.size());
    for(auto &ch : num)
    {
        cout<<ch<<' ';
    }
    system("pause");
    return 0;
}