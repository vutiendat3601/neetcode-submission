class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0, cnt = 0;
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        for (int num : nums) {
            int sub = num - last;
            if (sub == 1) {
                cnt++;
            } else if (sub) {
                ans = max(ans, cnt);
                cnt = 1;
            }
            last = num;
        }
        ans = max(ans, cnt);
        return ans;
    }
};

// Sorting, O(n.log(n))
