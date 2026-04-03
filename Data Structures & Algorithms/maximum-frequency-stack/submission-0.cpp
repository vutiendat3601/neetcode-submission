class FreqStack {
private:
    unordered_map<int, int> cnt;
    stack<pair<int, int>> st;

public:
    FreqStack() {}

    void push(int val) {
        cnt[val]++;
        stack<pair<int, int>> st2;
        pair<int, int> top;
        while (!st.empty() && (top = st.top()).second > cnt[val]) {
            st2.push(top);
            st.pop();
        }
        st.push({val, cnt[val]});
        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        pair<int, int> top = st.top();
        st.pop();
        cnt[top.first]--;
        return top.first;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */