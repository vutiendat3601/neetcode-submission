class Solution {
private:
    unordered_map<int, int> cache;

    int dfs(int n) {
        if (n <= 0) {
            return 0;
        }
        if (cache.count(n)) {
            return cache[n];
        }
        int ans = 1 + dfs(n - 1);
        for (int k = 2; k < n; k++) {
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