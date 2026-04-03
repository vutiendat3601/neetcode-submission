class Solution {
private:
    void quick_sort(vector<int>& nums) {
        quick_sort_execute(nums, 0, nums.size() - 1);
    }

    void quick_sort_execute(vector<int>& nums, int l, int r) {
        if (l < r) {
            int i = l - 1;
            for (int j = l; j < r; j++) {
                if (nums[j] < nums[r]) {
                    i++;
                    int tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                }
            }
            i++;
            int tmp = nums[r];
            nums[r] = nums[i];
            nums[i] = tmp;
            quick_sort_execute(nums, l, i - 1);
            quick_sort_execute(nums, i + 1, r);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums);
        return nums;
    }
};

// Quick Sort, time: O(n.log(n)), space: O(1)