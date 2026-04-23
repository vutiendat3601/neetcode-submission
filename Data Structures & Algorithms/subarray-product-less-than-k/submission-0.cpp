class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, m = 0, p = 1, ans = 0;
        while (r < n) {
            p *= nums[r];
            while (p >= k && l <= r) p /= nums[l], l++;
            if (p < k) {
                ans += r - l + 1;
            }
            r++;
        }
        return ans;
    }
};