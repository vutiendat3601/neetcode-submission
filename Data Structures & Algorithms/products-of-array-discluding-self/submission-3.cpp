class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), pref(n + 1, 1), suff(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] * nums[i - 1];
            suff[n - i] = suff[n - i + 1] * nums[n - i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = pref[i] * suff[i + 1];
        }
        return ans;
    }
};

// Prefix Sum, time: O(n), space: O(n)