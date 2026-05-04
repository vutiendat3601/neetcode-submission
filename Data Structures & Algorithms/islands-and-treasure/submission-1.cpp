class Solution {
   private:
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) visited[r][c] = 1, q.push({r, c});
            }
        }
        int k = 0;
        while (k = q.size()) {
            while (k--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : DIRECTIONS) {
                    int x = r + dr, y = c + dc;
                    bool ok = x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == INT_MAX;
                    if (ok && !visited[x][y]) {
                        visited[x][y] = 1, grid[x][y] = grid[r][c] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
};

// BFS, time: O(m.n), space: O(m.n)
