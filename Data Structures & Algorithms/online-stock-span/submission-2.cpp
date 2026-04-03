class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price) {
        int ans = 1;
        pair<int, int> t;
        while (!st.empty() && (t = st.top()).first <= price) {
            ans += t.second;
            st.pop();
        }
        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */