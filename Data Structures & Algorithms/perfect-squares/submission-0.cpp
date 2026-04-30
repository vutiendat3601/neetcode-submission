class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int k = sqrt(i); k > 0; k--)
                if (dp[i])
                    dp[i] = min(dp[i], dp[k * k] + dp[i - k * k]);
                else
                    dp[i] = dp[k * k] + dp[i - k * k];
        }
        return dp[n];
    }
};