class MinStack {
private:
    stack<int> st, st_min;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        int last = st_min.empty() ? INT_MAX : st_min.top();
        st_min.push(min(last, val));
    }
    
    void pop() {
        st.pop();
        st_min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }
};
