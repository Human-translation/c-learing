private:
    /*
    //两个栈分别存储
    stack<int> st; //存储原栈的元素
    stack<int> s; //存储栈内最小值
    int Minnum; //用来记录当前最小值是谁，当然此时的第二个栈的栈顶元素就是当前的最小值，我多此一举
    */


    //也可以用一个栈来存储，在每个原元素之间加上此区间的最小值
    stack<int> stac;
    int Minnum; //记录最小值的值

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        /*
        if(st.empty()){
            Minnum = x;
        }
        else{
            if(x < Minnum) Minnum = x;
        }
        st.push(x);
        s.push(Minnum);
        */

        if(stac.empty()) Minnum = x;
        else{
            if(x < Minnum) Minnum = x;
        }
        stac.push(x);
        stac.push(Minnum);
    }
    
    void pop() {
        /*
        st.pop();
        s.pop();
        if(!s.empty()) Minnum = s.top();
        else Minnum = INT_MIN;
        */


        stac.pop();
        stac.pop();
        if(!stac.empty()) Minnum = stac.top();
        else Minnum = INT_MIN;
    }
    
    int top() {
        /*
        if(!st.empty()) return st.top();
        return -1;
        */


        if(!stac.empty()){
            int num = stac.top();
            stac.pop();
            int res = stac.top();
            stac.push(num);

            return res;
        }
        return -1;
    }
    
    int getMin() {
        /*
        if(!s.empty()) return s.top();
        return -1;
        */


        if(!stac.empty()) return stac.top();
        return -1;
    }
