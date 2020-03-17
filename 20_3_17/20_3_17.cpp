#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std; 

    string replaceSpace(string s) {
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                string a = s.substr(0,i);
                string b = s.substr(i+1,s.size()-1);
                a += "%20";
                a += b;
                s = a;
            }
        }
        return s;
    }

    char firstUniqChar(string s) 
    {
        if(s.empty())
            return ' ';
        map<int,int> m;
        for(auto ch : s)
            m[ch]++;
        for(auto ch : s)
        {
            cout<<'1';
            if(m[ch] == 1)
            {
                cout<<'2'<<endl;
                return ch;                
            }
        }
        return ' ';
    }


    int findRepeatNumber(vector<int>& nums) {
        set<int> m;
        for(auto ch:nums)
        {
            if(m.count(ch))
                return ch;
            m.insert(ch);
        }
        return 0;
    }

    int main()
    {
        vector<int> num = {2, 3, 1, 0, 2, 5, 3};
        string s = {"leetcode"};
        cout<<findRepeatNumber(num)<<endl;
        system("pause");
        return 0;
    }