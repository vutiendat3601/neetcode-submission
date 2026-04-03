class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        char cs[n+1];
        int i = 0;
        for (char c : s) {
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')) {
                cs[i++]=tolower(c);
            }
        }
        cs[i]='\0';
        string cr_o(cs);
        string cr_c(cr_o.rbegin(), cr_o.rend());
        return cr_o == cr_c;
    }
};

// 2 Pointers, O(n)