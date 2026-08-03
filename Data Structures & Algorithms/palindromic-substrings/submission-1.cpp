class Solution {
   private:
    int check(string s, int l, int r) {
        int n = s.size(), ans = 0;
        while (0 <= l && r < n && s[l--] == s[r++])
            ans++;
        return ans;
    }
   public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) ans += check(s, i, i), ans += check(s, i, i + 1);
        return ans;
    }
};
