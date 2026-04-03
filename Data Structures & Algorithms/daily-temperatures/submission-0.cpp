class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (t[j] > t[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};

// Brute Force, O(n^2)