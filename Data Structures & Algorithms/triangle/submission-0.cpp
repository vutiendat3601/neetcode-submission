class Solution {
   public:
    int minimumTotal(vector<vector<int>>& dp) {
        int n = dp.size();
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c <= r; c++) {
                dp[r][c] += min(dp[r + 1][c], dp[r + 1][c + 1]);
            }
        }
        return dp[0][0];
    }
};