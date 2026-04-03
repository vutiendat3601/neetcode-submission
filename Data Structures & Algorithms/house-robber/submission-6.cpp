class Solution {
private:
    vector<int> cache;
    int dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (cache[i] == -1) {
           cache[i] =max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1));
        }
        return cache[i];
    }
public:
    int rob(vector<int>& nums) {
        cache.assign(nums.size(), -1);
        return dfs(nums, 0);
    }
};

// DFS, time: O(2^n), space: O(2^n)