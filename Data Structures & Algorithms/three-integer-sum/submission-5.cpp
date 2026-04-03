class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        for (int i = 0; i < n; i++) {
            int target = 0 - nums[i];
            if (nums[i] != last) {
                int l = i + 1, r = n - 1;
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum > target) {
                        r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        int j = r - 1;
                        while (j > l && nums[j] == nums[r]) {
                            j--;
                        }
                        r = j;
                    }
                }
            }
            last = nums[i];
        }
        return ans;
    }
};