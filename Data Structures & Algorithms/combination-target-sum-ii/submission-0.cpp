class Solution {
private:
    vector<vector<int>> ans;
    vector<int> nums, ans_item;
    int target;

    void backtrack(int k, int sum) {
        if (sum == target) {
            ans.push_back(vector<int>(ans_item.begin(), ans_item.end()));
            return;
        }
        int last = INT_MAX;
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] != last && sum + nums[i] <= target) {
                ans_item.push_back(nums[i]);
                backtrack(i + 1, sum + nums[i]);
                ans_item.pop_back();
            }
            last = nums[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->target = target;
        backtrack(0, 0);
        return ans;
    }
};