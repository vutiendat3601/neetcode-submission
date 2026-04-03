class Solution {
private:
    vector<unordered_map<string, int>> cache;

    int dfs(int n, int k, int last1, int last2) {
        string key = to_string(last1) + "," + to_string(last2);
        if (n == 1) {
            return last1 == last2 ? k - 1 : k;
        }
        int ans = 0;
        if (cache[n].count(key)) {
            return cache[n][key];
        }
        if (last1 == last2) {
            for (int i = 0; i < k; i++) {
                if (i != last1) {
                    ans += dfs(n - 1, k, i, last1);
                }
            }
        } else {
            for (int i = 0; i < k; i++) {
                ans += dfs(n - 1, k, i, last1);
            }
        }
        return (cache[n][key] = ans);
    }
public:
    int numWays(int n, int k) {
        cache = vector<unordered_map<string, int>>(n + 1, unordered_map<string, int>());
        return dfs(n, k, -1, -2);
    }
};
