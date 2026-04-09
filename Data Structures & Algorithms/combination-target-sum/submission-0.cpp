class Solution {
private:
    vector<int> nums, ans_item;
    set<vector<int>> ans;
    int target;

    void backtrack(int k, int cur_sum) {
        if (cur_sum == target) {
            ans.insert(vector<int>(ans_item.begin(), ans_item.end()));
        }
        if (k >= nums.size()) {
            return;
        }
        if (nums[k] + cur_sum <= target) {
            ans_item.push_back(nums[k]);
            backtrack(k, nums[k] + cur_sum);
            ans_item.pop_back();
        }
        backtrack(k + 1, cur_sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        backtrack(0, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
