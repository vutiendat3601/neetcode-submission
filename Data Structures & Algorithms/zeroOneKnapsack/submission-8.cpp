class Solution {
    /*
       private:
        int n;
        int dfs(int w, int k, vector<int>& profit, vector<int>& weight, vector<vector<int>>& cache)
       { if (k >= n) return 0; if (cache[k][w] < 0) { cache[k][w] = dfs(w, k + 1, profit, weight,
       cache); if (w >= weight[k]) cache[k][w] = max(cache[k][w], profit[k] + dfs(w - weight[k], k +
       1, profit, weight, cache));
            }
            return cache[k][w];
        }
    */
   public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for (int w = 1; w <= capacity; w++) {
            for (int k = n - 1; k >= 0; k--) {
                dp[k][w] = dp[k + 1][w];
                if (w >= weight[k]) dp[k][w] = max(dp[k][w], profit[k] + dp[k + 1][w - weight[k]]);
            }
        }
        return dp[0][capacity];
    }
};
