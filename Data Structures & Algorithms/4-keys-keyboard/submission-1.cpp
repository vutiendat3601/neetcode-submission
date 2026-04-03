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

/**
dfs(1, cur, clipboard) -> cur + max(1, clipboard)
dfs(2, cur, clipboard) -> cur + max(1, clipboard)

// ctrlA, ctrlC, ctrlV
dfs(3, cur, clipboard) -> max(1, clipboard)

*/