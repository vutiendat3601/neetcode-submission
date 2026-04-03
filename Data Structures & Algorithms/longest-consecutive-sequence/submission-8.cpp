class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        int last = 0, cnt = 0, ans = 0;
        for (auto& num : s) {
            if (num == last + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            last = num;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// Hashing, time: O(n), space: O(n)