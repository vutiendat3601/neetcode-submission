class Solution {
private:
    vector<unordered_map<int, int>> cache;

    int dfs(vector<vector<int>>& costs, int last_color, int i) {
        if (i >= costs.size()) {
            return 0;
        }
        if (!cache[i].count(last_color)) {
            int res = 1e9;
            for (int j = 0; j < 3; j++) {
                if (j != last_color) {
                    res = min(res, costs[i][j] + dfs(costs, j, i + 1));
                }
            }
            cache[i][last_color] = res;
        }
        return cache[i][last_color];
    }
public:
    int minCost(vector<vector<int>>& costs) {
        cache = vector<unordered_map<int, int>>(costs.size(), unordered_map<int, int>(3));
        return dfs(costs, -1, 0);
    }
};