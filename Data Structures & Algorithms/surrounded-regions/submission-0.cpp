class Solution {
private:
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, - 1}};
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    int m, n;

    void dfs(int r, int c) {
        visited[r][c] = 1;
        for (auto [dr, dc] : DIRECTIONS) {
            int x = r + dr, y = c + dc;
            bool ok = x >= 0 && y >= 0 && x < m && y < n && board[r][c] == 'O';
            if (ok && !visited[x][y])
                dfs(x, y);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        this->board = board, m = board.size(), n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O' && !visited[0][c])
                dfs(0, c);
            if (board[m - 1][c] == 'O' && !visited[m - 1][c])
                dfs(m - 1, c);
        }
        for (int r = 1; r < m - 1; r++) {
            if (board[r][0] == 'O' && !visited[r][0])
                dfs(r, 0);
            if (board[r][n - 1] == 'O' && !visited[r][n - 1])
                dfs(r, n - 1);
        }

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) 
                if (board[r][c] == 'O' && !visited[r][c])
                    board[r][c] = 'X';
    }
};
