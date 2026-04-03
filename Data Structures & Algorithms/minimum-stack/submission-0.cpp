class MinStack {
private:
    stack<int> st;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> st2;
        int mn = INT_MAX;
        do {
            mn = min(mn, st.top());
            st2.push(st.top());
            st.pop();
        } while (!st.empty());
        do {
            st.push(st2.top());
            st2.pop();
        } while (!st2.empty());
        return mn;
    }
};

// Brute Force, O(n) in getMin function
