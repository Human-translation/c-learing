class Solution {
public:
![EA54CBBD-C472-43F0-8E4D-049DC9444FBA.jpeg](https://pic.leetcode-cn.com/2982f427c2b1cc73470643e22550fc5669a4e5513dbb36f0662765a629b61888-EA54CBBD-C472-43F0-8E4D-049DC9444FBA.jpeg)
    int numWays(int n) {
        int dp[n+2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n+1; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }
        return dp[n+1];
    }
};
