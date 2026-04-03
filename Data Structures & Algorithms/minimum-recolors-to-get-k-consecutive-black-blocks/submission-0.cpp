class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), ans = INT_MAX;
        for (int i = 0; i <= n - k; i++) {
            int cnt = 0;
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(1)