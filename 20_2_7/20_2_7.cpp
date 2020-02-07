#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //直接模拟十进制加法运算法则
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>0;--i){
            if(digits[i]>9){
                digits[i-1]++;
                digits[i]%=10;
            }
        }
        //对最高位进行处理
        vector<int>::iterator it;
        it=digits.begin();
        if(digits[0]>9){
            digits[0]%=10;
            digits.insert(it,1);
        }
        return digits;
    }
};
