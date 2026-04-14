class Solution {
private:
    vector<vector<int>> grid;
    int m, n;
    vector<vector<bool>> visited;

    int dfs(int r, int c) {
        if (r >= m || c >= n)
            return 0;
        int ans = grid[r][c];
        visited[r][c] = 1;
        if (grid[r][c]) {
            for (int i = 0; i < m; i++)
                if (!visited[i][c])
                    ans += dfs(i, c);
            for (int j = 0; j < n; j++)
                if (!visited[r][j])
                    ans += dfs(r, j);
        }
        return ans;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        int ans = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c] && grid[r][c]) {
                    int cur_ans = dfs(r, c);
                    if (cur_ans > 1)
                        ans += cur_ans;
                }
            }
        }
        return ans;
    }
};