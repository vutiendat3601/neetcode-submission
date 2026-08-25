class Solution {
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

   public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache(m, vector<int>(n, INT_MAX));
        return dfs(0, 0, grid, cache);
    }
};