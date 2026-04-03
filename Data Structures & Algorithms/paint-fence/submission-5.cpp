class Solution {
private:
    vector<unordered_map<string, int>> cache;
    int dfs(const int n, const int k, int c, int cnt) {
        string key = to_string(c) + "," + to_string(cnt);
        if (n == 1) {
            return cnt < 2 ? k : k - 1;
        }
        if (!cache[n].count(key)) {
            for (int j = 0; j < k; j++) {
                if (j != c) {
                    cache[n][key] += dfs(n - 1, k, j, 1);
                } else {
                    if (cnt < 2) {
                        cache[n][key] += dfs(n - 1, k, j, cnt + 1);
                    }
                }
            }
        }
        return cache[n][key];
    }
public:
    int numWays(int n, int k) {
        cache = vector<unordered_map<string, int>>(n + 1);
        return dfs(n, k, -1, 0);
    }
};
