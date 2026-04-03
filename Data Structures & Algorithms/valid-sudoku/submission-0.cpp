class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), squares(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                int sq_idx = (i / 3) * 3 + (j / 3);
                if (c != '.') {
                    if (rows[i].count(c) || 
                        cols[j].count(c) ||
                        squares[sq_idx].count(c)
                    ) {
                        return 0;
                    }
                    rows[i].insert(c);
                    cols[j].insert(c);
                    squares[sq_idx].insert(c);
                }
            }
        }
        return 1;
    }
};
