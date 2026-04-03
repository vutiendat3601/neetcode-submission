class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size(), ans = 0;
        vector<bool> assigned(n);
        for (int i = 0; i < m; i++) {
            int j = 0, mn = -1;
            while (j < n) {
                if (s[j] >= g[i] && !assigned[j] && (mn < 0 || s[j] < s[mn])) {
                    mn = j;
                }
                j++;
            }
            if (mn > -1) {
                assigned[mn] = 1;
                ans++;
            }
        }
        return ans;
    }
};

// Brute Force, time: O(max(m, n)^2), space: O(1)