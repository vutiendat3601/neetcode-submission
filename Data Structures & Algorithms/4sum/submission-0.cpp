class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> res;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (0L + nums[i] + nums[j] + nums[k] + nums[l] ==
                            target) {
                            vector<int> tmp = {nums[i], nums[j], nums[k],
                                               nums[l]};
                            sort(tmp.begin(), tmp.end());
                            res.insert(tmp);
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

// Brute Force, time: O(n^4), space: O(1)