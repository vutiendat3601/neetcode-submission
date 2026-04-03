class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m;
        for (int i = 0; i < n; i++) {
            j = m + i;
            nums1[j] = nums2[i];
            while (j > 0 && nums1[j] < nums1[j - 1]) {
                nums1[j] = nums1[j - 1];
                nums1[j - 1] = nums2[i];
                j--;
            }
        }
    }
};

// Brute Force, time: O(n.m), space: O(1)