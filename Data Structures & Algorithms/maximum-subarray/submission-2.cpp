class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], mx_left = nums[0];
        for (int i = 1; i < n; i++) {
            mx_left = max(mx_left + nums[i], nums[i]);
            ans = max(ans, mx_left);
        }
        return ans;
    }
};

