class Solution {
   private:
    string ans = "";
    void check(string s, int l, int r) {
        int n = s.size();
        while (0 <= l && r < n && s[l] == s[r]) {
            int len = r - l + 1;
            if (len > ans.size())
                ans = s.substr(l, len);
            l--, r++;
        }
    }

   public:
    string longestPalindrome(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++)
            check(s, i, i), check(s, i, i + 1);

        return ans;
    }
};
