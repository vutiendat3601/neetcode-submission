class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, m = 0, ans = 0;
        unordered_map<int, int> cnt;
        while (r < n) {
            cnt[nums[r]]++;
            if (cnt.size() > k) {
                cnt.erase(nums[m]), m++, l = m;
            }
            if (cnt.size() == k) {
                while (cnt[nums[m]] != 1) cnt[nums[m]]--, m++;
                ans += m - l + 1;
            }
            r++;
        }
        return ans;
    }
};

// Sliding Window, time: O(n), space: O(n)