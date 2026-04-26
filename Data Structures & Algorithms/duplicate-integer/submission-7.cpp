class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), less<int>());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return 1;
            }
        }
        return 0;
    }
};

// Sorting, time: O(n.log(n)), space: O(1)