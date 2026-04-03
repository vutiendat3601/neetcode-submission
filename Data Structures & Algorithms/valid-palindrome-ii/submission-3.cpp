class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return 0;
            l++;
            r--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l < r) {
            if (s[l] != s[r])
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            l++;
            r--;
        }
        return 1;
    }
};