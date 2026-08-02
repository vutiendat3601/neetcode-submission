class Solution {
   private:
    int m, n;
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& cache) {
        if (r == m - 1 && c == n - 1) return 1;
        if (cache[r][c] < 0) {
            cache[r][c] = 0;
            if (r + 1 < m && !grid[r + 1][c]) cache[r][c] += dfs(r + 1, c, grid, cache);
            if (c + 1 < n && !grid[r][c + 1]) cache[r][c] += dfs(r, c + 1, grid, cache);
        }
        return cache[r][c];
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return (grid[0][0] || grid[m - 1][n - 1]) ? 0 : dfs(0, 0, grid, cache);
    }
};