class Solution {
   private:
    int n;
    unordered_map<string, int> cache;
    int dfs(vector<vector<int>>& costs, int k, int last) {
        if (k >= n) return 0;
        string key = to_string(k) + "," + to_string(last);

        if (!cache.count(key)) {
            cache[key] = INT_MAX;
            for (int i = 0; i < 3; i++) {
                if (i != last) cache[key] = min(cache[key], costs[k][i] + dfs(costs, k + 1, i));
            }
        }
        return cache[key];
    }

   public:
    int minCost(vector<vector<int>>& costs) {
        n = costs.size();
        return dfs(costs, 0, -1);
    }
};