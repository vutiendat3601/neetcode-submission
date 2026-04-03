class Solution {
private:
    int dfs(vector<int>& prices, int i, bool buy) {
        if (i >= prices.size()) {
            return 0;
        }
        int cooldown = dfs(prices, i + 1, buy);
        if (buy) {
            int b = dfs(prices, i + 1, 0) - prices[i];
            return max(b, cooldown);
        }
        int s = dfs(prices, i + 2, 1) + prices[i];
        return max(s, cooldown);
    }
public:
    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, 1);
    }
};
