class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 1), suff(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * nums[i];
            suff[n - 1 - i] = nums[n - 1 - i] * suff[n - i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = pref[i] * suff[i + 1];
        }
        return ans;
    }
};

// Prefix Product + Suffix Product, time: O(n)