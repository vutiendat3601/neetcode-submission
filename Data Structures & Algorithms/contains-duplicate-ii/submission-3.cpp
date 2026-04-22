class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        unordered_set<int> unq;
        while (r < n) {
            if (r - l > k) unq.erase(nums[l++]);
            if (unq.count(nums[r])) return 1;
            unq.insert(nums[r++]);
        }
        return 0;
    }
};