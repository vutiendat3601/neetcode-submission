class Solution {
private:
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    string word;

    vector<pair<int, int>> get_squares(int r, int c) {
        vector<pair<int, int>> ans;
        for (auto& [x, y] : directions) {
            int new_r = r + x, new_c = c + y;
            if (0 <= new_r && new_r < m && 0 <= new_c && new_c < n) {
                ans.push_back({new_r, new_c});
            }
        }
        return ans;
    }

    bool backtrack(int i, int j, int k) {
        if (k >= word.size()) {
            return 1;
        }
        for (auto& [r, c] : get_squares(i, j)) {
            if (!visited[r][c] && board[r][c] == word[k]) {
                visited[r][c] = 1;
                if (backtrack(r, c, k + 1)) {
                    return 1;
                }
                visited[r][c] = 0;
            }
        }
        return 0;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        m = board.size(), n = board[0].size();
        visited.assign(m, vector<bool>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    visited[i][j] = 1;
                    if (backtrack(i, j, 1)) {
                        return 1;
                    }
                    visited[i][j] = 0;
                }
            }
        }
        return 0;
    }
};