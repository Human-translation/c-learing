#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v={0,0,0,0,0};


    if(find(v.begin(), v.end(), 1) != nullptr)
        cout<<true;
    return 0;
}