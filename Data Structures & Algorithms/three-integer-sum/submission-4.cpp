class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> tmp_ans;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> res = {nums[i], nums[j], nums[k]};
                        sort(res.begin(), res.end());
                        tmp_ans.insert(res);
                    }
                }
            }
        }
        return vector<vector<int>>(tmp_ans.begin(), tmp_ans.end());
    }
};

// Brute force, time: O(n^3)