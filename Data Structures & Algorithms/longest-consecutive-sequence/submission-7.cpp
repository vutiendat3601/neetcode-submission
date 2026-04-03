class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int res = 1, k = 0, tmp = nums[i] + 1;
            while (k < n) {
                if (tmp == nums[k]) {
                    res++;
                    tmp++;
                    k = 0;
                } else {
                    k++;
                }
            }
            ans = max(ans, res);
        }
        return ans;
    }
};
