class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0, l = 0;
        unordered_map<char, int> pos;
        for (int i = 0; i < n; i++) {
            if (pos.count(s[i])) {
                l = max(l, pos[s[i]] + 1);
            }
            pos[s[i]] = i;
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};

// Sliding Window, time: O(n), space: O(n)