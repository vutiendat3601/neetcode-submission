class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int product = nums[i];
            ans = max(ans, product);
            for (int j = i + 1; j < n; j++) {
                product *= nums[j];
                ans = max(ans, product);
            }
        }

        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(1)