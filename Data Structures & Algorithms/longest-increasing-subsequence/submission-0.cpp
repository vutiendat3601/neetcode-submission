class Solution {
private:
    int dfs(vector<int>& nums, int i, int last) {
        if (i >= nums.size()) {
            return 0;
        }
        int ans = dfs(nums, i + 1, last);
        if (nums[i] > last) {
            ans = max(ans, 1 + dfs(nums, i + 1, nums[i]));
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums, 0, INT_MIN);
    }
};
