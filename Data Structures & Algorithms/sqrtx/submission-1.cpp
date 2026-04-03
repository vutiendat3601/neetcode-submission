class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long mid2 = (long)mid * mid;
            if (mid2 > x) {
                r = mid - 1;
            } else if (mid2 < x) {
                ans = mid;
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return ans;
    }
};

// Binary Search, time: O(log(n)), space: O(1)