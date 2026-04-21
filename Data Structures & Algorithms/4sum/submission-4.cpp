typedef long long ll;
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int a = 0; a < n - 3; a++) {
            if (nums[a] == (a ? nums[a - 1] : INT_MIN)) continue;
            for (int b = a + 1; b < n - 2; b++) {
                if (nums[b] == (b > a + 1 ? nums[b - 1] : INT_MIN)) continue;
                int c = b + 1, d = n - 1;
                ll diff = (ll)target - nums[a] - nums[b];
                while (c < d) {
                    ll sum = (ll)nums[c] + nums[d];
                    if (sum < diff) {
                        c++;
                    } else if (sum > diff) {
                        d--;
                    } else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++, d--;
                        while (c < d && nums[d] == nums[d + 1]) d--;
                    }
                }
            }
        }
        return ans;
    }
};