class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            char c = s[l];
            char d = s[r];
            c = tolower(c);
            d = tolower(d);
            if (!('a' <= c && c <= 'z') && !('0' <= c && c <= '9')) {
                l++;
            } else if (!('a' <= d && d <= 'z') && !('0' <= d && d <= '9')) {
                r--;
            } else if (c != d) {
                return 0;
            } else {
                l++;
                r--;
            }
        }
        return 1;
    }
};

// 2 Pointers, O(n)