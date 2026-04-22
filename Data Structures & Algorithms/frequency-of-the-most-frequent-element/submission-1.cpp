class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = 0, ans = 0;
        long sum = 0;
        while (r < n) {
            sum += nums[r];
            long mx = (long) nums[r] * (r - l + 1);
            while (mx - sum > k)
                sum -= nums[l++], mx -= nums[r];
            ans = max(ans, r - l + 1), r++;
        }
        return ans;
    }
};

// Sliding Window, time: O(n), space: O(1)