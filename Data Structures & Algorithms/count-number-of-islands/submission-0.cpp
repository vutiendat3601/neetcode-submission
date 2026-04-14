class Solution {
private:
    int m, n;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;

    void dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
            return;
        visited[r][c] = 1;
        if (r > 0 && !visited[r - 1][c])
            dfs(r - 1, c);
        if (r < m - 1 && !visited[r + 1][c])
            dfs(r + 1, c);
        if (c > 0 && !visited[r][c - 1])
            dfs(r, c - 1);
        if (c < n - 1 && !visited[r][c + 1])
            dfs(r, c + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid, m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        int ans = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c] && grid[r][c] == '1')
                    ans++, dfs(r, c);
            }
        }
        return ans;
    }
};
