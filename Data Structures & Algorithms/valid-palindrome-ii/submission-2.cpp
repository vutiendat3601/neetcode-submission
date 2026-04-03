class Solution {
private:
    bool validPalindrome(string s, int l, int r, bool replaced) {
        if (l < r) {
            if (s[l] == s[r]) {
                return validPalindrome(s, l + 1, r - 1, replaced);
            }
            if (replaced) {
                return 0;
            }
            return validPalindrome(s, l + 1, r, 1) ||
                   validPalindrome(s, l, r - 1, 1);
        }
        return 1;
    }

public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1, 0);
    }
};