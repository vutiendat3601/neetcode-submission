class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<string> s;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                // int mx_ij = max(nums[i], nums[j]);
                // int mn_ij = min(nums[i], nums[j]);
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> vals = {nums[i], nums[j], nums[k]};
                        sort(vals.begin(), vals.end());
                        string key = to_string(vals[0]) + ',' + to_string(vals[1]) + ',' + to_string(vals[2]);
                        if (!s.count(key)) {
                            s.insert(key);
                            ans.push_back({nums[i], nums[j], nums[k]});
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// Brute Force, O(n^3)
