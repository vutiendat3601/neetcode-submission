class Solution {
private:
    vector<vector<int>> ans;
    vector<vector<bool>> visited;
    int color, orig_color, m, n;

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || ans[i][j] != orig_color)
            return;
        visited[i][j] = 1;
        ans[i][j] = color;
        
        vector<pair<int, int>> d = {{i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j +1}};
        for (auto &[f,s] : d)
            dfs(f,s);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ans = image, orig_color = image[sr][sc], this->color = color, 
        m = image.size(), n = image[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        dfs(sr, sc);
        return ans;
    }
};