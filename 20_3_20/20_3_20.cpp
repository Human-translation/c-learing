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

    
    
int cuttingRope(int n) {
        if(n <= 3) return n-1;
        long rs = 1;
        while (n > 4) {
            rs *= 3;
            rs %= 1000000007;
            n -= 3;
        }
        return (rs * n) % 1000000007;
    }

    bool check(vector<int> & v,int L,int R);

    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 2) return true;
        return check(postorder,0,postorder.size()-1);
    }

    bool check(vector<int> & v,int L,int R)
    {
        if(L >= R) return true;
        int root = v[R];
        int mid = L;
        // 找到左子树部分
        for(;mid<R;mid++)
        {
            if(v[mid] > root)  break;
        }
        // 找到右子树部分
        int j = mid;
        for(;j<R;j++)
        {
            if(v[j] < root) return false;
        }
        bool left = true,right = true;
        // 检查左子树部分是否为二叉树
        if(mid > L) left = check(v,L,mid-1);
        // 检查右子树部分是否为二叉树
        if(mid < R) right = check(v,mid,R-1);
        return left && right;
    }


    int main()
    {
        vector<int> num={1,3,2,5,4};
        //cout<<nthUglyNumber(11);
        cout<<verifyPostorder(num)<<endl;
        system("pause");
        return 0;
    }