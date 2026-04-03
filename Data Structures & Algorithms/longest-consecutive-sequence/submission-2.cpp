class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = nums[i] + 1, cnt = 1;
            while (s.count(cur)) {
                cnt++;
                cur++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
