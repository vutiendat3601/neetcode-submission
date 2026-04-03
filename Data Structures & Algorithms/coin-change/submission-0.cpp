class Solution {
private:
    int dfs(vector<int>& coins, int i, int amount) {
        if (!amount) {
            return 0;
        }
        if (amount < 0 || i >= coins.size()) {
            return -1;
        }
        int selected = dfs(coins, i, amount - coins[i]);
        int skipped = dfs(coins, i + 1, amount);
        if (selected >= 0 && skipped >= 0) {
            return min(1 + selected, skipped);
        }
        if (selected < 0 && skipped < 0) {
            return -1;
        }
        return selected >= 0 ? 1 + selected : skipped;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        return dfs(coins, 0, amount);
    }
};

// DFS, time: O(2^n), space: O(2^n)