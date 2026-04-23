class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, m = 0, ans = 0;
        unordered_map<int, int> cnt;
        unordered_set<int> unq;
        while (r < n) {
            cnt[nums[r]]++;
            unq.insert(nums[r]);
            if (unq.size() > k) {
                while (cnt[nums[l]] != 1) cnt[nums[l]]--, l++;
                cnt[nums[l]]--, unq.erase(nums[l]), l++;
            }
            if (unq.size() == k) {
                unordered_set<int> e;
                m = r + 1;
                while (e.size() < k) e.insert(nums[m - 1]), m--;
                ans += m - l + 1;
            }
            r++;
        }
        return ans;
    }
};