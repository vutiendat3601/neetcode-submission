class Solution {
   private:
    int n;
    int dfs(int k, int w, vector<int>& profit, vector<int>& weight,
            unordered_map<string, int>& cache) {
        if (k >= n) return 0;
        string key = to_string(k) + "_" + to_string(w);
        if (!cache.count(key)) {
            if (w - weight[k] >= 0)
                cache[key] = max(profit[k] + dfs(k + 1, w - weight[k], profit, weight, cache),
                                 dfs(k + 1, w, profit, weight, cache));
            else
                cache[key] = dfs(k + 1, w, profit, weight, cache);
        }
        return cache[key];
    }

   public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        n = profit.size();
        unordered_map<string, int> cache;
        return dfs(0, capacity, profit, weight, cache);
    }
};
