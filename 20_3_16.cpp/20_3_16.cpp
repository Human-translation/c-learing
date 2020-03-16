#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std; 


    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int> s;
        auto it = nums.begin();
        while(it != nums.end())
        {
            if(s.empty())
                s.push(*it);
            else if(s.top() == *it)
                s.push(*it);
            else if(s.top() != *it)
                s.pop();
            it++;
        }
        return s.top();
    }

    int main()
    {
        vector<int> num = {3,2,3};
        majorityElement(num);
        return 0;
    }