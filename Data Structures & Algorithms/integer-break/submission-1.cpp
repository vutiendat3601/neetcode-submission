class Solution {
   public:
    int dfs(int n, unordered_map<int, int>& cache) {
        if (n < 2) return 1;
        if (!cache.count(n)) {
            cache[n] = n;
            for (int i = 1; i <= n; i++) cache[n] = max(cache[n], i * dfs(n - i, cache));
        }
        return cache[n];
    }
    int integerBreak(int n) {
        unordered_map<int, int> cache;
        cache[n] = 0;
        for (int i = 1; i < n; i++)
            cache[n] = max(cache[n], i * dfs(n - i, cache));
        return cache[n];
    }
};