class Solution {
private:
    int n;
    vector<int> queen;
    vector<vector<string>> ans;
    vector<string> ans_item;
    void backtrack(int k) {
        if (k >= n) {
            ans.push_back(ans_item);
            return;
        }
        for (int col = 0; col < n; col++) {
            bool cont = 1;
            for (int r = 0; r < k; r++) {
                if (queen[r] == col || abs(queen[r] - col) == k - r) {
                    cont = 0;
                    break;
                }
            }
            if (cont) {
                queen[k] = col;
                string tmp(n, '.');
                tmp[col] = 'Q';
                ans_item.push_back(tmp);
                backtrack(k + 1);
                ans_item.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n, queen = vector<int>(n);
        backtrack(0);
        return ans;
    }
};
