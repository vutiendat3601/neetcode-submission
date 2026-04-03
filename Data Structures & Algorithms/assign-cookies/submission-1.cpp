class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size(), i = 0, j = 0, ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < m && j < n) {
            if (g[i] <= s[j]) {
                i++, j++, ans++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

// Sorting + 2-pointers, time: O(max(m, n).log(max(m, n))), space: O(1)