class Solution {
   private:
    int dfs(int k, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& cache) {
        int n = profit.size();
        if (k >= n) return 0;
        if (cache[k][w] < 0) {
            if (w >= weight[k])
                cache[k][w] = max(profit[k] + dfs(k + 1, w - weight[k], profit, weight, cache),
                                  dfs(k + 1, w, profit, weight, cache));
            else
                cache[k][w] = dfs(k + 1, w, profit, weight, cache);
        }
        return cache[k][w];
    }

   public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();
        vector<vector<int>> cache(n, vector<int>(capacity + 1, -1));
        return dfs(0, capacity, profit, weight, cache);
    }
};
