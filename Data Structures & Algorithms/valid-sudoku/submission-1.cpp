class Solution {
private:
    const int N = 9;

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), area(9);
        for (int i = 0; i < N; i++) {
            // check row
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    if (rows[i].count(board[i][j])) {
                        return 0;
                    }
                    if (cols[j].count(board[i][j])) {
                        return 0;
                    }
                    int z = 3 * (i / 3) + j / 3;
                    if (area[z].count(board[i][j])) {
                        return 0;
                    }
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    area[z].insert(board[i][j]);
                }
            }
        }
        return 1;
    }
};

// Hashing, time: O(1), space: O(1)