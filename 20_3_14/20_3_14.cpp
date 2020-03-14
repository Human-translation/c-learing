#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 


    int lengthOfLIS(vector<int>& nums) {
        int num = 1;
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                    if(num < dp[i])
                        num = dp[i];
                }
            }
        }
        return num;
    }


    vector<vector<int>> largeGroupPositions(string S) 
    {
        vector<vector<int>> arr;
        vector<char> ptr; 
        int count = 1;
        int m = arr.size();
        for(int i=0;i<S.size();i++)
        {
            if(ptr.size() == 0)
            {
                ptr.push_back(S[i]);
                continue;
            }
            if(S[i] == ptr.back())
            {
                arr.resize(m+1);
                if(count == 1)
                    arr[m].push_back(i-1);
                count++;    
                if(S[i] != S[i+1])
                {
                    if(count >= 3)
                    {
                        arr[m].push_back(i);
                        m++;                        
                    }
                    else
                    {
                        arr[m].pop_back();
                        arr.resize(m);
                    }
                    count = 1;                    
                }          
            }
            ptr.push_back(S[i]);
        }
        return arr;
    }

    int consecutiveNumbersSum(int N)
    {
        int count = 0;
        int j = 0;
        while(N>0)
        {
            N -= j++;
            if(N/j>0 && N%j==0)
                count++;
        }
        return count;
    }

    string maskPII(string s) {

        int pos = s.find('@',0);
        string arr;
        if(pos == -1)
        {
            string ptr;
            for(int i=0;i<s.size();i++)
            {
                if(s[i] >= '0' && s[i]<= '9')
                    ptr += s[i];
            }
            if(ptr.size() == 10)
            {
                arr += "***-***-";
                arr += ptr[6];
                arr += ptr[7];
                arr += ptr[8];
                arr += ptr[9];
            }
            else
            {
                arr += "+***-***-***-";
                arr += ptr[8];
                arr += ptr[9];
                arr += ptr[10];
                arr += ptr[11];
            }
            
        }
        else
        {
            if(s[0]-'a' < 0)
                s[0] += 32;
            if(s[pos-1]-'a' < 0)
                s[pos-1] += 32;
            string ptr = s.substr(pos,s.size());
            for(auto& ch :ptr)
            {
                if(ch >='A' && ch<= 'Z')
                    ch += 32;
            }
            arr += s[0];
            arr += "*****";
            arr += s[pos-1];
            arr += ptr;
        }
        
        return arr;
    }


    int main()
    {
        string s ={"LeetCode@LeetCode.com"};
        vector<int> num={1,3,6,7,9,4,10,5,6};

        cout<<maskPII(s);
        system("pause");
        return 0;
    }