#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int main()
{
    vector<int> num1={1,2,3};
    vector<int> num2={2,1,3};
    vector<int> num3;
    num3 = num2;
    sort(num2.begin(),num2.end());
    if(num1 == num2)
    {
        cout<<'1'<<endl;
    }
    system("pause");
    return 0;
}*/

    int maxProfit(vector<int>& prices) {
        int kmax = 2;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i].resize(kmax+1);
            for(int k=0;k<=kmax;k++)
            {
                dp[i][k].resize(2);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            dp[i][0][0]=0;
            dp[i][0][1]=INT_MIN;
            for(int k=1;k<=kmax;k++)
            {
                if(i-1 == -1)
                {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        

        return dp[n-1][kmax][0];
    }

    int main()
    {
        vector<int> num={2,4,1};
        cout<<maxProfit(num);
        system("pause");
        return 0;
    }