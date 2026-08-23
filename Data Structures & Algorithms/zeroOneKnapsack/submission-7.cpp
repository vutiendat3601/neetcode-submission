class Solution {
   private:
    int n;
    int dfs(int w, int k, vector<int>& profit, vector<int>& weight, vector<vector<int>>& cache) {
        if (k >= n) return 0;
        if (cache[k][w] < 0) {
            cache[k][w] = dfs(w, k + 1, profit, weight, cache);
            if (w >= weight[k])
                cache[k][w] = max(cache[k][w],
                           profit[k] + dfs(w - weight[k], k + 1, profit, weight, cache));
        }
        return cache[k][w];
    }

   public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        n = profit.size();
        vector<vector<int>> cache(n, vector<int>(capacity + 1, -1));
        return dfs(capacity, 0, profit, weight, cache);
    }
};
