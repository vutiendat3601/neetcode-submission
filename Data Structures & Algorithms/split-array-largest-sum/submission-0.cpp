class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, mx = 0, ans = INT_MAX;
        for (auto&num:nums) {
            sum += num;
            mx = max(mx, num);
        }
        for (int t = mx; t <= sum; t++) {
            int sub_sum = 0, cnt = 1;
            for (int i = 0; i < n; i++) {
                if (sub_sum + nums[i] <= t) {
                    sub_sum += nums[i];
                } else {
                    cnt++;
                    sub_sum = nums[i];
                }
            }
            if (cnt <= k) {
                ans = min(ans, t);
            }
        }
        return ans;
    }
};