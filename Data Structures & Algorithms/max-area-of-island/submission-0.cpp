class Solution {
private:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;

    int dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || !grid[r][c])
            return 0;
        visited[r][c] = 1;
        int ans = 1;
        if (r > 0 && !visited[r - 1][c])
            ans += dfs(r - 1, c);
        if (r < m - 1 && !visited[r + 1][c])
            ans += dfs(r + 1, c);
        if (c > 0 && !visited[r][c - 1])
            ans += dfs(r, c - 1);
        if (c < n - 1 && !visited[r][c + 1])
            ans += dfs(r, c + 1);
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid, m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        int ans = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c] && grid[r][c])
                    ans = max(ans, dfs(r, c));
            }
        }
        return ans;
    }
};
