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
        string rev_cs(cs);
        reverse(rev_cs.begin(), rev_cs.end());
        return rev_cs == cs;
    }
};
