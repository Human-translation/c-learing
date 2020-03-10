#include <iostream>
#include <vector>
using namespace std;
/*
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

//1
    int ans;
    int dp(TreeNode* root)
    {
        if(!root)   return 0;

        int l = dp(root->left);
        int r = dp(root->right);
        ans += abs(l-r);
        return root->val+l+r;
    }

    int findTilt(TreeNode* root) {
        ans = 0;
        dp(root);
        return ans;
    }


//2
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p || !q)  return p==q;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && p->val==q->val;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)  return false;
        return isSubtree(s->left,t) || isSubtree(s->right,t) || isSameTree(s,t);
    }

//3
    TreeNode* dg(vector<int>& nums,int left,int right)
    {
        if(left == right)
            return NULL;
        int i=left,max = nums[left],j=i;
        for(;i<right;i++)
        {
            if(max < nums[i])
            {
                max = nums[i];  
                j = i;                 
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = dg(nums,left,j);
        root->right = dg(nums,j+1,right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dg(nums,0,nums.size());
    }

    int main()
    {
        vector<int> nums={3,2,1,6,0,5};
        constructMaximumBinaryTree(nums);
        system("pause");
        return 0;
    }
*/
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<vector<int>> opt(n);
        for(int i=0;i<n;i++)
            opt[i].resize(2);
        for(int i=0;i<n;i++)
        {
            if(i-1 == -1)
            {
                opt[i][0] = 0;
                opt[i][1] = -prices[i];
                continue;
            }
            opt[i][0] = max(opt[i-1][0],opt[i-1][1]+prices[i]);
            opt[i][1] = max(opt[i-1][1],opt[i-1][0]-prices[i]);
        }
        return opt[n-1][0];
    }

    int maxProfit2(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
            dp[i].resize(2);
        int dp_i_2 = 0;
        for(int i=0;i<n;i++)
        {
            if(i-1 == -1 )
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);


            dp[i][1] = max(dp[i-1][1],dp_i_2-prices[i]);
            dp_i_2 = dp[i-1][0];
        }
        return dp[n-1][0];
    }

    int main()
    {
        vector<int> num={1,2,3,0,2};
        cout<<maxProfit2(num);
        system("pause");
        return 0;
    }

