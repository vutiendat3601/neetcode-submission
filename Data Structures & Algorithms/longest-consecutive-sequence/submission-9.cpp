class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto &num:s) {
            if (!s.count(num - 1)) {
                int z = num, len = 1;
                while (s.count(z + 1)) {
                    len++;
                    z++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
