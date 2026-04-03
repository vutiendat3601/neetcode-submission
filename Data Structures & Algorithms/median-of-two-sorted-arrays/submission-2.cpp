class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        if (n1 < n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int a1 = 0, a2 = n1 - 1, b1 = 0, b2 = n2 - 1;
        int l = -1, r = n1 - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            a1 = mid < 0 ? INT_MIN : nums1[mid];
            a2 = mid + 1 >= n1 ? INT_MAX : nums1[mid + 1];
            b1 = n / 2 - (mid + 2) < 0 ? INT_MIN : nums2[n / 2 - (mid + 2)];
            b2 = n / 2 - (mid + 1) >= n2 ? INT_MAX : nums2[n / 2 - (mid + 1)];
            if (a1 > b2) {
                r = mid - 1;
            } else if (b1 > a2) {
                l = mid + 1;
            } else {
                break;
            }
        }
        return n & 1 ? min(a2, b2) : (max(a1, b1) + min(a2, b2)) / 2.0;
    }
};
