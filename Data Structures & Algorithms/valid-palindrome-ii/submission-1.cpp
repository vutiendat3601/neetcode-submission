class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l <= r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                break;
            }
        }
        int l1 = l + 1, r1 = r, l2 = l, r2 = r - 1;
        while (l1 <= r1) {
            if (s[l1] == s[r1]) {
                l1++;
                r1--;
            } else {
                break;
            }
        }
        if (l1 <= r1) {
            while (l2 <= r2) {
                if (s[l2] == s[r2]) {
                    l2++;
                    r2--;
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
};

// 2-pointers, time: O(n), space: O(1)