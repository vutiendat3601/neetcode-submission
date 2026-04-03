class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0, n = h.size();
        for (int i = 0; i < n; i++) {
            int mn = h[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, h[j]);
                ans = max(ans, mn * (j - i + 1));
            }
        }
        return ans;
    }
};

// Brute Force, time: O(n^2)

