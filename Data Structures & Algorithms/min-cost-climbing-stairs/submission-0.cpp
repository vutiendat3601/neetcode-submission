class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), i = 2;
        vector<int> ans(n + 1, 0);
        while (i <= n) {
            ans[i] = min(ans[i - 1] + cost[i - 1], ans[i - 2] + cost[i - 2]);
            i++;
        }
        return ans[n];
    }
};

// Dynamic Programming, time: O(n), space: O(n)