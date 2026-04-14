class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    if (r - 1 < 0 || !grid[r - 1][c])
                        ans++;
                    if (r + 1 >= m || !grid[r + 1][c])
                        ans++;
                    if (c - 1 < 0 || !grid[r][c - 1])
                        ans++;
                    if (c + 1 >= n || !grid[r][c + 1])
                        ans++;
                }
            }
        }
        
        return ans;
    }
};