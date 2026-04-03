class Solution {
private:
    vector<int> cache = vector<int>(51);

    int dfs(int n) {
        if (n <= 0) {
            return 0;
        }
        if (cache[n]) {
            return cache[n];
        }
        int ans = 1 + dfs(n - 1); // type 'A'
        for (int k = 2; k < n; k++) { // CtrlA + CtrlC always has at least 2 operations.
            ans = max(ans, dfs(n - k - 2) * (k + 1));
        }
        return cache[n] = ans;
    }
public:
    int maxA(int n) {
        return dfs(n);
    }
};

// DFS, time: O(n^2), space: O(n)
