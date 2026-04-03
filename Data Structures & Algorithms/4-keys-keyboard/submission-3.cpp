class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
            for (int j = i + 3; j <= n; j++) {
                dp[j] = max(dp[j], dp[i] * (j - i - 1));
            }
        }
        return dp[n];
    }
};
