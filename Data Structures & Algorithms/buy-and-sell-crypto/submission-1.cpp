class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        stack<int> st;
        st.push(prices[0]);

        for (int i = 1; i < n; i++) {
            if (prices[i] < st.top()) {
                st.push(prices[i]);
            }
            ans = max(ans, prices[i] - st.top());
        }

        return ans;
    }
};

// Stack, O(n)