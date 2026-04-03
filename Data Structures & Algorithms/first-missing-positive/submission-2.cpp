class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        bool cont = 1;
        while (cont) {
            cont = 0;
            for (auto& num : nums) {
                if (num == ans) {
                    ans++;
                    cont = 1;
                    break;
                }
            }
        }
        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(1)