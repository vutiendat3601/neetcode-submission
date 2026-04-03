class Solution {
private:
    void merge(vector<int>& nums, int l, int r, int mid) {
        vector<int> ans(r - l + 1);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                ans[k++] = nums[i++];
            } else {
                ans[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            ans[k++] = nums[i++];
        }
        while (j <= r) {
            ans[k++] = nums[j++];
        }
        i = 0, j = l;
        while (j <= r) {
            nums[j++] = ans[i++];
        }
    }
    void m_sort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            m_sort(nums, l, mid);
            m_sort(nums, mid + 1, r);
            merge(nums, l, r, mid);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        m_sort(nums, 0, n - 1);
        return nums;
    }
};