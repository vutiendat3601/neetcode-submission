class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < (1<<n); i++) {
            vector<int> item;
            for (int j = n - 1; j >= 0; j--) {
                if ((i >> j) & 1) {
                    item.push_back(nums[n - 1 - j]);
                }
            }
            ans.push_back(item);
        }
        return ans;
    }
};
