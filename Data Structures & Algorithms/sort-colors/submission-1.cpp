class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), i = -1;
        for (int j = 0; j < 2; j++) {
            for (int k = i + 1; k < n; k++) {
                if (nums[k] == j) {
                    i++;
                    int tmp = nums[k];
                    nums[k] = nums[i];
                    nums[i] = tmp;
                }
            }
        }
    }
};

// 2-pointers, time: O(n), space: O(1)