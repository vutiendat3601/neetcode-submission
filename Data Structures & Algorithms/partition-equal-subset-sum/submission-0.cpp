class Solution {
private:
    bool dfs(vector<int>& nums, int i, int target) {
    if (!target) {
        return 1;
    }
    if (i >= nums.size()) {
        return 0;
    }
    bool ans = 0;
    if (nums[i] <= target) {
        ans = dfs(nums, i + 1, target - nums[i]);
    }
    if (ans) {
        return 1;
    }
    return dfs(nums, i + 1, target);
}
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto &num:nums) {
            sum+=num;
        }
        if (sum&1){return 0;}
        return dfs(nums,0,sum/2);
    }
};

// DFS, time: O(2^n), space: O(n)