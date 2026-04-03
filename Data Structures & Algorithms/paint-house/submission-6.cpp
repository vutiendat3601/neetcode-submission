class Solution {
private:
    unordered_map<string, int> cache;

    int dfs(vector<vector<int>>& costs, int i, int c) {
        if (i >= costs.size()) {
            return 0;
        }
        string key = to_string(i)+","+to_string(c);
        if (!cache.count(key)) {
            cache[key] = INT_MAX;
            for (int z = 0; z < 3; z++) {
                if (z != c) {
                    cache[key] = min(cache[key], costs[i][z] + dfs(costs, i + 1, z));
                }
            }
        }
        return cache[key];
    }
public:
    int minCost(vector<vector<int>>& costs) {
        return dfs(costs, 0, -1);
    }
};