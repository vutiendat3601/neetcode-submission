class Solution {
private:
    vector<int> nums, ans_item;
    set<vector<int>> ans;
    unordered_map<int, int> cnt;
    int n;

    void backtrack(int i) {
        if (i >= n) {
            ans.insert(vector<int>(ans_item.begin(), ans_item.end()));
            return;
        }
        for (auto &[k, v] : cnt) {
            if (v) {
                cnt[k]--;
                ans_item.push_back(k);
                backtrack(i + 1);
                ans_item.pop_back();
                cnt[k]++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->n = nums.size();
        for (auto & num:nums) {
            cnt[num]++;
        }
        backtrack(0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};