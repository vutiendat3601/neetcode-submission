class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = 0, ans = INT_MAX;
        while (r < n) {
            if (r >= l + k) l++;
            if (r == l + k - 1) ans = min(ans, nums[r] - nums[l]);
            r++;
        }
        return ans;
    }
};