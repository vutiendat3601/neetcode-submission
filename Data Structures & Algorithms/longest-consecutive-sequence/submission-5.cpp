class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set s(nums.begin(), nums.end());
        for (int num : nums) {
            if (!s.count(num-1)) {
                int cur = num+1, cnt = 1;
                while (s.count(cur)) {
                    cnt++;
                    cur++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

// Sorting, O(n.log(n))
