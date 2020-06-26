//方法一：
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        return {numbers[1], numbers[0]};
    }
};

//方法二：
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[1] = numbers[0] - numbers[1] + (numbers[0] = numbers[1]);
        return numbers;
    }
};

//方法三：
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[1] = numbers[1] - numbers[0];
        numbers[0] = numbers[0] + numbers[1];
        numbers[1] = numbers[0] - numbers[1];
        return numbers;
    }
};

//方法四：
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return  numbers;
    }
};

