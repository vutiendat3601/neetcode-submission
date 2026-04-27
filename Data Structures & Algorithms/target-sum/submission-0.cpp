class Solution {
   private:
    int n, target;

    int dfs(vector<int>& nums, int k, int sum) {
        if (k >= n) return sum == target ? 1 : 0;
        return dfs(nums, k + 1, sum + nums[k]) + dfs(nums, k + 1, sum - nums[k]);
    }

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), this->target = target;
        return dfs(nums, 0, 0);
    }
};
