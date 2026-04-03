class StockSpanner {
private:
    stack<int> st;
    unordered_map<int, int> cnt;

public:
    StockSpanner() {}

    int next(int price) {
        int ans = 1, t = -1;
        while (!st.empty() && (t = st.top()) <= price) {
            st.pop();
            ans += cnt[t];
        }
        st.push(price);
        cnt[price] = ans;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */