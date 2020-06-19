class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //需要考虑负数的情况
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int a=(nums[n]-1)*(nums[n-1]-1);
        int b=(nums[0]-1)*(nums[1]-1);
        if(a>b)
            return a;
        else
            return b;
    }
};
