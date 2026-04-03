class Solution {
   public:
    bool isPalindrome(string s) {
        string cs = "";
        for (char c : s) {
            if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9')) {
                cs += c;
            } else if ('A' <= c && c <= 'Z') {
                char lower_c = c + 32;
                cs += lower_c;
            }
        }
        int n = cs.size();
        for (int i = 0; i < n / 2; i++) {
            if (cs[i] != cs[n - 1 - i]) {
                return 0;
            }
        }
        return 1;
    }
};
