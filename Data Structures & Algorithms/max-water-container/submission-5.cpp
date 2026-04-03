class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, min(height[i], height[j]) * (j - i));
            }
        }
        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(1)