class Solution {
private:
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> heights;
    int m, n;
    
    void dfs(int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = 1;
        for (auto [dr, dc] : DIRECTIONS) {
            int x = r + dr, y = c + dc;
            bool ok = x >= 0 && y >= 0 && x < m && y < n && !visited[x][y];
            if (ok && heights[x][y] >= heights[r][c])
                dfs(x, y, visited);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights, m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> visited_pacific(m, vector<bool>(n, 0)), 
                             visited_atlantic(m, vector<bool>(n, 0));
        for (int r = 0; r < m; r++)
            if (!visited_pacific[r][0])
                dfs(r, 0, visited_pacific);
        for (int c = 0; c < n; c++)
            if (!visited_pacific[0][c])
                dfs(0, c, visited_pacific);

        for (int r = 0; r < m; r++)
            if (!visited_atlantic[r][n - 1])
                dfs(r, n - 1, visited_atlantic);
        for (int c = 0; c < n; c++)
            if (!visited_atlantic[m - 1][c])
                dfs(m - 1, c, visited_atlantic);

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (visited_pacific[r][c] && visited_atlantic[r][c])
                    ans.push_back({r, c});
        return ans;
    }
};
