class StockSpanner {
private:
    stack<int> st;

public:
    StockSpanner() {}

    int next(int price) {
        stack<int> tmp;
        int ans = 1;
        while (!st.empty() && st.top() <= price) {
            ans++;
            tmp.push(st.top());
            st.pop();
        }
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
        st.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */