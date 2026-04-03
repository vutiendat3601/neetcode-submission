class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            // find left max
            int mx_left = h[i], mx_right = h[i];
            for (int j = 0; j < i; j++) {
                mx_left = max(mx_left, h[j]);
            }
            // find right max
            for (int j = i+1; j < n; j++) {
                mx_right = max(mx_right, h[j]);
            }
            ans += min(mx_left, mx_right) - h[i];
        }
        return ans;
    }
};

// Brute Force, O(n^2)
