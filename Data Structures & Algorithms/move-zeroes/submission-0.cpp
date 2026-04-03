class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        while (i < n) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
            i++;
        }
        while (j < n) {
            nums[j++] = 0;
        }
    }
};

// 2-pointers, time: O(n), space: O(1)