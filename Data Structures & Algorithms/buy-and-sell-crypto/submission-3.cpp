class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (prices[r] < prices[l]) {
                l = r;
            }
            ans = max(ans, prices[r] - prices[l]);
        }

        return ans;
    }
};

// 2 Pointers, O(n)