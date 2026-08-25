class Solution {
    /*
       private:
        int m, n;
        int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& cache) {
            if (r == m - 1 && c == n - 1) return grid[m - 1][n - 1];
            if (cache[r][c] == INT_MAX) {
                if (r == m - 1)
                    cache[r][c] = grid[r][c] + dfs(r, c + 1, grid, cache);
                else if (c == n - 1)
                    cache[r][c] = grid[r][c] + dfs(r + 1, c, grid, cache);
                else
                    cache[r][c] =
                        grid[r][c] + min(dfs(r, c + 1, grid, cache), dfs(r + 1, c, grid, cache));
            }
            return cache[r][c];
        }
    */
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1000));
        dp[m - 1][n] = 0, dp[m][n - 1] = 0;
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                dp[r][c] = grid[r][c] + min(dp[r + 1][c], dp[r][c + 1]);
            }
        }
        return dp[0][0];
    }
};