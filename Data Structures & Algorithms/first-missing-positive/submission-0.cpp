class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        while (1) {
            bool found = 1;
            for (auto& num : nums) {
                if (missing == num) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return missing;
            }
            missing++;
        }
        return missing;
    }
};

// Brute Force, time: O(n^2), space: O(1)