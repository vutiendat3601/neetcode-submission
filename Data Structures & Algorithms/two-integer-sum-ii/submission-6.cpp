class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};

// Brute Force, time: O(n^2), space: O(1)