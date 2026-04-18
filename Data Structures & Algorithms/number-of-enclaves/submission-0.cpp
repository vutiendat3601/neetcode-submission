class Solution {
private:
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        visited[r][c] = 1;
        for (auto& [dr, dc] : DIRECTIONS) {
            int x = r + dr, y = c + dc;
            bool ok = x >= 0 && y >= 0 && x < m && y < n && grid[x][y];
            if (ok && !visited[x][y])
                dfs(x, y, grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        visited.assign(m, vector<bool>(n, 0));

        for (int c = 0; c < n; c++) {
            if (grid[0][c] && !visited[0][c])
                dfs(0, c, grid);
            if (grid[m - 1][c] && !visited[m - 1][c])
                dfs(m - 1, c, grid);
        }

        for (int r = 1; r < m - 1; r++) {
            if (grid[r][0] && !visited[r][0])
                dfs(r, 0, grid);
            if (grid[r][n - 1] && !visited[r][n - 1])
                dfs(r, n - 1, grid);
        }

        for (int r = 1; r < m - 1; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (grid[r][c] && !visited[r][c])
                    ans++;
            }
        }
        return ans;
    }
};