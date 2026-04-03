class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            } else {
                ans += res;
                res = 0;
            }
        }
        ans += res;
        return ans;
    }
};

// Peak–Valley Greedy, time: O(n), space: O(1)