class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum > goal) break;
                if (sum == goal) ans++;
            }
        }
        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(1)