class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = ans[1] = 1;
        int i = 2;
        while (i <= n) {
            ans[i] = ans[i - 1] + ans[i - 2];
            i++;
        }
        return ans[n];
    }
};

// Dynamic programming, time: O(n), space: O(n)
