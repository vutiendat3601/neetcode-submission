class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), last2 = 0, last1 = nums[0];
        for (int i = 1; i < n; i++) {
            int preLast2 = last2;
            last2 = last1;
            last1 = max(last2, preLast2 + nums[i]);
        }
        return last1;
    }
};

// Dynamic Programming, time: O(n), space: O(1)