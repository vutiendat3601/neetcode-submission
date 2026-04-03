class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            int streak = 0;
            int j = 0;
            while (j < n) {
                if (nums[j] == cur) {
                    streak++;
                    cur++;
                    j = 0;
                    continue;
                }
                j++;
            }
            ans = max(ans, streak);
        }
        return ans;
    }
};
