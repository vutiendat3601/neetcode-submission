class Solution {
   public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for (int w = 1; w <= capacity; w++) {
            for (int i = n - 1; i >= 0; i--) {
                dp[i][w] = dp[i + 1][w];
                if (w >= weight[i]) dp[i][w] = max(dp[i][w], profit[i] + dp[i + 1][w - weight[i]]);
            }
        }
        return dp[0][capacity];
    }
};
