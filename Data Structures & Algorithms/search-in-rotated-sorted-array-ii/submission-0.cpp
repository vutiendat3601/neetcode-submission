class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto& num : nums) {
            if (num == target) {
                return 1;
            }
        }
        return 0;
    }
};

// Brute Force, time: O(log(n)), space: O(1)