#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std; 

    vector<int> constructArr(vector<int>& a) {
        vector<int> left(a.size()),right(a.size());
        for(int i=0;i<a.size();i++)
        {
            if(i==0)
            {
                left[i] = 1;
                continue;
            }
            left[i] = left[i-1] * a[i-1];
        }
        for(int i=a.size()-1;i>=0;i--)
        {
            if(i==a.size()-1)
            {
                right[i] = 1;
                continue;
            }
            right[i] = right[i+1] * a[i+1];
        }
        return a;
    }


    int lastRemaining(int n, int m) {
        int last = 0;
        for(int i = 2; i <= n; ++i){
            last = (last + m) % i;
            cout<<last<<' ';
        }
        return last;
    }

    int add(int a, int b) {
        while(b)
        {
            int c = (a & b) << 1;
            a = a ^ b;  
            b = c;          
        }
        return a;
    }

    int main()
    {
        vector<int> num = {1,2,3,4,5};
        //vector<int> arr = constructArr(num);
        cout<<add(-1,2);
        system("pause");
        return 0;
    }