class MinStack {
private:
    stack<int> st, st2;
public:
    MinStack() {
        st2.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        st2.push(min(st2.top(), val));
    }
    
    void pop() {
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

// 2 Stacks, O(1) in getMin function
