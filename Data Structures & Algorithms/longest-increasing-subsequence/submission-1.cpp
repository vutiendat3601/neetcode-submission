class Solution {
private:
    unordered_map<string, int> cache;
    int dfs(vector<int>& nums, int i, int last) {
        if (i >= nums.size()) {
            return 0;
        }
        string key = to_string(i) + "," + to_string(last);
        if (cache.count(key)) {
            return cache[key];
        }
        cache[key] = dfs(nums, i + 1, last);
        if (nums[i] > last) {
            cache[key] = max(cache[key], 1 + dfs(nums, i + 1, nums[i]));
        }
        return cache[key];
    }

public:
    int lengthOfLIS(vector<int>& nums) { return dfs(nums, 0, INT_MIN); }
};
