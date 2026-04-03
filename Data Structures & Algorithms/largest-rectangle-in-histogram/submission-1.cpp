class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int ml = i, mr = i;
            for (int j = i - 1; j >= 0; j--) {
                if (h[j] < h[i]) {
                    break;
                }
                ml = j;
            }
            for (int j = i + 1; j < n; j++) {
                if (h[j] < h[i]) {
                    break;
                }
                mr = j;
            }
            ans = max(ans, (mr - ml + 1) * h[i]);
        }
        return ans;
    }
};

// Brute Force, O(n^2)