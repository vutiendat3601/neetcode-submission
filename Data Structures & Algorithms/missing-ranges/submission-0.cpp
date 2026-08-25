class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        for (auto& num : nums) {
            if (num > lower)
                ans.push_back({lower, num - 1});
            lower = num + 1;
        }
        if (lower <= upper)
            ans.push_back({lower, upper});
        return ans;
    }
};
