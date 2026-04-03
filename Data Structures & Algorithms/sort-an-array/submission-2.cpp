class Solution {
private:
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int j = l - 1;
            for (int i = l; i < r; i++) {
                if (nums[i] < nums[r]) {
                    j++;
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
            j++;
            int tmp = nums[j];
            nums[j] = nums[r];
            nums[r] = tmp;
            quick_sort(nums, l, j - 1);
            quick_sort(nums, j + 1, r);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
        return nums;
    }
};

// Quick Sort, time: O(n.log(n)), space: O(1)