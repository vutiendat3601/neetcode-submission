class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for (int i = 0; i < k; i++) {
            int tmp = nums[n - 1];
            int j = n - 1;
            while (j > 0) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[0] = tmp;
        }
    }
};

// Brute Force, time: O(n^2), space: O(1)