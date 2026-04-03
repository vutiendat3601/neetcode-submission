class Solution {
private:
    bool dfs(vector<int>&nums, int i, int target) {
        if (target == 0) {
            return 1;
        }
        if (i >= nums.size()) {
            return 0;
        }
        // Select item at index i
        if (target >= nums[i] && dfs(nums, i + 1, target - nums[i])) {
            return 1;
        }
        // Not select item at index i
        return dfs(nums, i + 1, target);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum & 1) {
            return 0;
        }
        return dfs(nums, 0, sum / 2);
    }
};

// two subsets such that the sum of the elements in both subsets is equal
// DFS, time: O(2^n), space: O(2^n)