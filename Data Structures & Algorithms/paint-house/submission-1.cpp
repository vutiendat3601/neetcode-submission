class Solution {
private:
    vector<vector<int>> cache;

    int dfs(vector<vector<int>>& costs, int last_color, int i) {
        if (i >= costs.size()) {
            return 0;
        }
        if (cache[i][last_color + 1] == -1) {
            int res = 1e9;
            for (int j = 0; j < 3; j++) {
                if (j != last_color) {
                    res = min(res, costs[i][j] + dfs(costs, j, i + 1));
                }
            }
            cache[i][last_color + 1] = res;
        }
        return cache[i][last_color + 1];
    }
public:
    int minCost(vector<vector<int>>& costs) {
        cache = vector<vector<int>>(costs.size(), vector<int>(4, -1));
        return dfs(costs, -1, 0);
    }
};