class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string t(s.begin(), s.end());
            t.erase(i, 1);
            string p1(t.begin(), t.begin() + n / 2),
                p2(t.rbegin(), t.rbegin() + n / 2);
            if (p1 == p2) {
                return 1;
            }
        }
        return 0;
    }
};

// Brute Force, time: O(n^2), space: O(n)