class Solution {
private:
    vector<int> cache;
    int dfs(vector<int>&nums, int n, int i) {
        if (i >= n) {
            return 0;
        }
        if (cache[i] == -1) {
            cache[i] =  max(nums[i] + dfs(nums, n, i+2), dfs(nums,n,i+1));
        }
        return cache[i];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        cache.assign(n, -1);
        int left = dfs(nums, n-1, 0);
        cache.assign(n, -1);
        int right = dfs(nums, n, 1);
        return n > 1 ? max(left, right) : nums[0];
    }
};
