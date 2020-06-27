class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> ss;
        int left,right;
        string res="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                if(ss.empty()) left=i;//栈为空，且当前字符为左括号，则判定为 最外左括号
                ss.push(S[i]);
            } 
            if(!ss.empty()&&S[i]==')')  ss.pop();
            if(ss.empty()) //栈再次为空，则当前位置判断为 最外右括号
            {
                right=i;
                res+=S.substr(left+1,right-left-1);
            }
            
        }
        return res;

    }
};
