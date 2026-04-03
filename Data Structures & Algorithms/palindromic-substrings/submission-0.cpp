class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (0 <= l && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
            l = i, r = i + 1;
            while (0 <= l && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};

// Dynamic Programming, time: O(n), space: O(1)