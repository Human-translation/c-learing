#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2;i<=n;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0] = cost[0];
        for(int i=1;i<=cost.size();i++)
        {
            if(i==1)
            {
                dp[i] = cost[i];
                continue;
            }
            if(i==cost.size())
            {
                dp[i] = min(dp[i-1] , dp[i-2]);
                break;
            }
            dp[i] = min(dp[i-1], dp[i-2])+cost[i];
        }
        for(auto ch:dp)
            cout<<ch<<' ';
        return dp[cost.size()];
    }


    int waysToStep(int n) {
        long long dp_i1 = 0;
        long long dp_i2 = 0;
        long long dp_i3 = 1;
        long long dp_i = 0;
        for(int i=0;i<n;i++)
        {
            dp_i = dp_i1+dp_i2+dp_i3;
            dp_i1 = dp_i2;
            dp_i2 = dp_i3;
            dp_i3 = dp_i;
            cout<<dp_i3<<endl;
        }
        return dp_i3;
    }


    int main()
    {
        vector<int> num={0,0,0,1};
        cout<<waysToStep(61);
        system("pause");
        return 0;
    }