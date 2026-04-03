class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans1 = nums[0], ans2 = ans1;
        if (n > 1) {
            ans2 = max(ans1, nums[1]);
        }
        for (int i = 2; i < n; i++) {
            int preAns1 = ans1;
            ans1 = ans2;
            ans2 = max(ans2, preAns1 + nums[i]);
        }
        return ans2;
    }
};

// Dynamic programming, time: O(n), space: O(1)