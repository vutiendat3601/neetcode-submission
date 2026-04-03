class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 1;
        vector<int> ans(n);
        for (auto& num : nums) {
            if (num > 0) {
                ans[l] = num;
                l += 2;
            } else {
                ans[r] = num;
                r += 2;
            }
        }
        return ans;
    }
};

// 2-pointers, time: O(n), space: O(1)