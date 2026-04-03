class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            if (!m[num]) {
                m[num] = 1 + m[num - 1] + m[num+1];
                m[num - m[num - 1]] = m[num];
                m[num + m[num + 1]] = m[num];
                ans = max(ans, m[num]);
            }
        }
        return ans;
    }
};

// Sorting, O(n.log(n))
