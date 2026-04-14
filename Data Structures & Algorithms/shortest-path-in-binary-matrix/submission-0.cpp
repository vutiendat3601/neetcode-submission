class Solution {
private:
    int n;
    const vector<pair<int, int>> CHANGES = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    vector<pair<int, int>> get_directions(int x, int y) {
        vector<pair<int, int>> ans;
        for (auto& [dx, dy] : CHANGES) {
            int i = x + dx, j = y + dy;
            if (0 <= i && i < n && 0 <= j && j < n)
                ans.push_back({i, j});
        }
        return ans;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        int k = 0, ans = 1;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        if (!grid[0][0])
            q.push({0, 0});
        while (k = q.size()) {
            while (k--) {
                auto [x, y] = q.front();
                q.pop();
                visited[x][y] = 1;
                if (x == n - 1 && y == n - 1)
                    return ans;
                for (auto& [i, j] : get_directions(x, y)) {
                    if (!visited[i][j] && !grid[i][j])
                        q.push({i, j});
                }
            }
            ans++;
        }
        return -1;
    }
};