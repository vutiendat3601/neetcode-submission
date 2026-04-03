class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return 1;
                }
            }
        }
        return 0;
    }
};

// Brute Force, O(n^2)