#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <memory.h>
#include <stdlib.h>
#include <math.h>
using namespace std;     

    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int up = 0,back = matrix.size()-1,left = 0,right = matrix[0].size()-1;
        vector<int> arr;
        while(up <= back && left <= right)
        {
            for(int i=up,j=left;j<=right;j++)
            {
                arr.push_back(matrix[i][j]);
                if(j == right)
                    up++;
            }
            
            if(up > back || left > right)
                return arr;

            for(int i=up,j=right;i<=back;i++)
            {
                arr.push_back(matrix[i][j]);
                if(i == back)
                    right--;
            }

            if(up > back || left > right)
                return arr;

            for(int i=back,j=right;j>=left;j--)
            {
                arr.push_back(matrix[i][j]);
                if(j == left)
                    back--;
            }

            if(up > back || left > right)
                return arr;

            for(int i=back,j=left;i>=up;i--)
            {
                arr.push_back(matrix[i][j]);
                if(i == up)
                    left++;
            }
        }
        return arr;
    }



    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(!nums.size())
            return nums;
        for(int i=0;i<nums.size()-k+1;i++)
        {
            for(int j=i;j<i+k;j++)
            {
                if(nums[j] > nums[i])
                    nums[i] = nums[j];
            } 
        }
        nums.resize(nums.size()-k+1);
        return nums;
    }

    vector<double> twoSum(int n) 
    {
        int dp[15][70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i ++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = i; j <= 6*i; j ++) {
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur <= 0) 
                    {
                        break;
                    }
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i ++) {
            ret.push_back(dp[n][i] * 1.0 / all);
        }
        return ret;
    }

    int MYmin(int x,int y,int z)
    {
        int min = x<y?x:y;
        return min<z?min:z;
    }

        int nthUglyNumber(int n) {
        vector<int> arr;
        if(n == 0)
            return 0;
        arr.resize(n);
        arr[0] = 1;
        int num2 = 0,num3 = 0,num5 = 0;
        int m = 1;
        for(int i = 1;i<n;i++)
        {
            m = MYmin(arr[num2]*2,arr[num3]*3,arr[num5]*5);
            if(m == arr[num2]*2)
                num2++;
            if(m == arr[num3]*3)
                num3++;
            if(m == arr[num5]*5)
                num5++; 
            arr[i] = m;  
        }
        return m;
    }


    int translateNum(int num) 
    {
        string nums = to_string(num);
        int f1 = 1;
        int f2 = 1;
        int f3;
        for(int i=1;i<nums.size();i++)
        {
            cout<<nums[i]-'0' + (nums[i-1]-'0')*10<<endl;
            if(nums[i]-'0' + (nums[i-1]-'0')*10 >= 10 && nums[i]-'0' + (nums[i-1]-'0')*10 <= 25)
                f3 = f1 + f2;
            else
                f3 = f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }

    int main()
    {
        /*
        vector<vector<int>> num(4);
        
        num[0].push_back(1);
        num[0].push_back(2);
        num[0].push_back(3);
        num[0].push_back(4);
        num[1].push_back(5);
        num[1].push_back(6);
        num[1].push_back(7);
        num[1].push_back(8);
        num[2].push_back(9);
        num[2].push_back(10);
        num[2].push_back(11);
        num[2].push_back(12);
        num[3].push_back(13);
        num[3].push_back(14);
        num[3].push_back(15);
        num[3].push_back(16);
        */


        vector<int> num={1,3,-1,-3,5,3,6,7};
        //cout<<nthUglyNumber(11);
        cout<<translateNum(26)<<endl;
        system("pause");
        return 0;
    }