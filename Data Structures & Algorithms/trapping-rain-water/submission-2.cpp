class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        vector<int> left_mxs(n, 0), right_mxs(n, 0);
        left_mxs[0] = h[0];
        right_mxs[n - 1] = h[n - 1];
        for (int i = 1; i < n; i++) {
            left_mxs[i] = max(left_mxs[i - 1], h[i]);
            right_mxs[n - 1 - i] = max(right_mxs[n - i], h[n - 1 - i]);
        }
        for (int i = 0; i < n; i++) {
            ans += min(left_mxs[i], right_mxs[i]) - h[i];
        }
        return ans;
    }
};

// Prefix, Suffix Arrays, O(n)
