class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        for (int i =0;i<n - 2;i++) {
            if (nums[i] != last) {
                last = nums[i];
                int l = i + 1, r = n - 1, target = -nums[i];
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) {
                            l++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// Sorting, O(n^2)
