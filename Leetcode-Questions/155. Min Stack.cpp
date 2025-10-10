class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        long long value = (long long)(val);
        if (st.empty()) {
            st.push(val);
            min = val;
        } else {
            if (val > min)
                st.push(val);
            else {
                st.push(2 * value * 1LL - min);
                min = val;
            }
        }
    }
    
    void pop() {
        if (st.empty())
            return;
        long long x = st.top();
        st.pop();

        if (x < min) {
            min = 2 * min - x;
        }
    }
    
    int top() {
        if (st.empty())
            return -1;
        long long x = st.top();
        if (x < min) {
            return min;
        }
        return x;      
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
