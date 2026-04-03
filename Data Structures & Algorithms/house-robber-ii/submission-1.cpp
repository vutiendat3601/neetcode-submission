class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return n > 1 ? max(rob(nums, n - 1, 0), rob(nums, n, 1)) : nums[0];
    }

    int rob(vector<int>& nums, int n, int k) {
        if (k >= n) {
            return 0;
        }
        int last2 = 0, last1 = nums[k];
        k++;
        while (k < n) {
            int preLast2 = last2;
            last2 = last1;
            last1 = max(last1, preLast2 + nums[k]);
            k++;
        }
        return last1;
    }
};

// Dynamic Programming, time: O(n), space: O(1)