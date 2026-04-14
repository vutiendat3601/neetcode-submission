class Solution {
private:
    vector<pair<int, int>> DIRECTIONS = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, ans = -1, k = 0, m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> s_pos;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    fresh++;
                else if (grid[r][c] == 2)
                    s_pos.push_back({r, c});
            }
        }
        if (!fresh)
            return 0;
        queue<pair<int, int>> q;
        for (auto& pos : s_pos)
            q.push(pos), visited[pos.first][pos.second] = 1;
        
        while (k = q.size()) {
            while (k--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : DIRECTIONS) {
                    int i = x + dx, j = y + dy;
                    bool ok = i >= 0 && j >= 0 && i < m && j < n;
                    if (ok && !visited[i][j] && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        visited[i][j] = 1;
                    }
                }
            }
            ans++;
        }
        return fresh ? -1 : ans;
    }
};
