class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int lastI = INT_MIN;
        for (int i = 0; i < n - 3; i++) {
            if (nums[i] != lastI) {
                int lastJ = INT_MIN;
                for (int j = i + 1; j < n - 2; j++) {
                    if (nums[j] != lastJ) {
                        int l = j + 1, r = n - 1;
                        long diff = target - (long)(nums[i] + nums[j]);
                        while (l < r) {
                            int sum = nums[l] + nums[r];
                            if (sum < diff) {
                                l++;
                            } else if (sum > diff) {
                                r--;
                            } else {
                                ans.push_back(
                                    {nums[i], nums[j], nums[l], nums[r]});
                                r--;
                                l++;
                                while (l < r && nums[l] == nums[l - 1]) {
                                    l++;
                                }
                            }
                        }
                    }
                    lastJ = nums[j];
                }
            }
            lastI = nums[i];
        }
        return ans;
    }
};

// 2-pointers, time: O(n^3), space: O(1)