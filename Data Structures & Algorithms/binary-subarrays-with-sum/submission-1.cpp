class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), l = 0, m = 0, r = 0, ans = 0, sum = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal) sum -= nums[l++], m = l;
            if (l <= r && sum == goal) {
                while (m < r && !nums[m]) m++;
                ans += m - l + 1;
            }
            r++;
        }
        return ans;
    }
};