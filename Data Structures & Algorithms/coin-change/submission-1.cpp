class Solution {
private:
    int dfs(vector<int>& coins, int i, int amount) {
        if (!amount) {
            return 0;
        }
        if (amount < 0 || i >= coins.size()) {
            return 1e9;
        }
        int selected = dfs(coins, i, amount - coins[i]);
        int skipped = dfs(coins, i + 1, amount);
        return min(1 + selected, skipped);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = dfs(coins, 0, amount);
        return ans < 1e9 ? ans : -1;
    }
};

// DFS, time: O(2^n), space: O(2^n)