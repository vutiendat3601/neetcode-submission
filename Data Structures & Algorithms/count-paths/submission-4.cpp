class Solution {
   private:
    int m, n;
    int dfs(int r, int c, vector<vector<int>>& cache) {
        if (r == m - 1 || c == n - 1) return 1;
        if (cache[r][c] < 0) cache[r][c] = dfs(r + 1, c, cache) + dfs(r, c + 1, cache);
        return cache[r][c];
    }

   public:
    int uniquePaths(int m, int n) {
        int ans = 0;
        this->m = m, this->n = n;
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(0, 0, cache);
    }
};
