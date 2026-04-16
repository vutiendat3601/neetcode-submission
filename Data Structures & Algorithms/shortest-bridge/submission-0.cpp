class Solution {
   private:
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    pair<int, int> findFirstOne(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                if (grid[x][y]) return {x, y};
        return {};
    }
    void init(vector<vector<int>>& grid, queue<pair<int, int>>& mq) {
        int n = grid.size(), k = 0;
        auto st = findFirstOne(grid);
        queue<pair<int, int>> q;
        q.push(st);
        visited[st.first][st.second] = 1;
        while (k = q.size()) {
            while (k--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : DIRECTIONS) {
                    int x = r + dr, y = c + dc;
                    bool ok = x >= 0 && y >= 0 && x < n && y < n && !visited[x][y];
                    if (ok) {
                        if (grid[x][y])
                            q.push({x, y});
                        else
                            mq.push({x, y});
                        visited[x][y] = 1;
                    }
                }
            }
        }
    }

   public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), k = 0, level = 1;
        visited.assign(n, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        init(grid, q);
        while (k = q.size()) {
            while (k--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : DIRECTIONS) {
                    int x = r + dr, y = c + dc;
                    bool ok = x >= 0 && y >= 0 && x < n && y < n && !visited[x][y];
                    if (ok) {
                        if (grid[x][y])
                            return level;
                        else
                            q.push({x, y});
                        visited[x][y] = 1;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};