#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> num1;
    vector<vector<int>> num2;
    num1.resize(2);
    num2.resize(3);

    cout<<num1[0].size()<<endl;
    system("pause");
    return 0;
}