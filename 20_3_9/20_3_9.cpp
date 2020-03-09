#include <iostream>
#include <vector>
using namespace std;
/*
void dp(vector<int> arr,int wight)
{
    vector<int> opt;
    opt.push_back(0);
    int coin;
    for(int i=1;i<=wight;i++)
    {
        coin = 99999;
        if(i-1>=0)   
            coin = min(coin,opt[i-1]+1);
        if(i-5>=0)   
            coin = min(coin,opt[i-5]+1);
        if(i-11>=0)   
            coin = min(coin,opt[i-11]+1);
        opt.push_back(coin);
    }
    for(auto ch : opt)
    cout<<ch<<' ';
}

void dp2(vector<int> arr,int wight)
{
    vector<int> opt(wight+1,1);
    
    opt[0] = 0;
    for(int i=1;i<=wight;i++)
    {
        for(int j =0;j<arr.size();j++)
        {
            if(arr[j] <= i)
                opt[i] = min(opt[i],opt[i-arr[j]]+1);
        }
    }
    
    for(auto ch : opt)
        cout<<ch<<' ';
}

int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        for(auto ch : dp)
            cout<<ch<<' ';
        cout<<endl;
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        for(auto ch : dp)
            cout<<ch<<' ';
        return dp[amount] > amount ? -1 : dp[amount];
    }

    int dp3(vector<int> arr,int len)
    {
        vector<int> opt(len,1);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j] < arr[i])
                    opt[i] = max(opt[i],opt[j]+1);
            }            
        }
        for(auto ch:opt)
            cout<<ch<<' ';
    }

    
    int count = 0;

    int findNumberOfLIS(vector<int>& nums) {
        vector<int> opt;
        vector<int> nummax(nums.size(),0);
        opt.resize(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    opt[i] = max(opt[i],opt[j]+1);   
                }
                
            }
            nummax[opt[i]]++;
        }
        for(auto ch:opt)
            cout<<ch<<' ';
        cout<<endl;
        for(auto ch:nummax)
            cout<<ch<<' ';
        cout<<endl;
        return 2;
    }

    int findNumberOfLIS(vector<int>& nums);
int main()
{
    vector<int> num = {2,2,2,2,2};
    cout<<findNumberOfLIS(num);
    system("pause");
    return 0;
}




    int findNumberOfLIS(vector<int>& nums) {
        vector<int> counts = vector<int>(nums.size(), 1); //代表i结尾的最长子序列个数
        vector<int> lengths = vector<int>(nums.size(), 1);//代表i结尾的最长子序列长度
        int maxLength = 1, res = 0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[j] >= lengths[i]) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } else if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j];
                    }
                }
            }
            maxLength = max(maxLength, lengths[i]);
        }
        for (int i=0; i<nums.size(); i++) {
            cout<<lengths[i]<<' '<<counts[i]<<endl;
            if (lengths[i] == maxLength) {
                res += counts[i];
            }
        }
        return res;
    }
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++)
        dp[i].resize(2);
    for(int i=0;i<n;i++)
    {
        if(i-1 == -1)
        {
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
            continue;
        }
        dp[i][0] = max(dp[i-1][0] ,dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1] ,-prices[i]);
    }
    return dp[n-1][0];
}

int main()
{
    vector<int> num = {7,1,5,3,6,4};
    cout<<maxProfit(num);
    system("pause");
    return 0;
}
