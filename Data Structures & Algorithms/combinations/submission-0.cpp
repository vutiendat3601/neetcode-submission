class Solution {
private:
    int n, k;
    vector<vector<int>> ans;
    void backtrack(vector<int> res, int i, int j) {
        if (i >= k) {
            ans.push_back(res);
            return;
        }
        if (j == n) {
            return;
        }
        backtrack(res, i, j + 1);
        res.push_back(j + 1);
        backtrack(res, i + 1, j + 1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        backtrack({}, 0, 0);
        return ans;
    }
};