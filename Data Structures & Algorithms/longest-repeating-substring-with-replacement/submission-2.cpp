class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        vector<char> chs;
        char last = '\0';
        for (char& c : s) {
            if (c != last) {
                chs.push_back(c);
            }
            last = c;
        }
        for (char& ch : chs) {
            int cnt = 0, l = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != ch) {
                    cnt++;
                }
                while (cnt > k) {
                    if (s[l] != ch) {
                        cnt--;
                    }
                    l++;
                }
                ans = max(ans, i - l + 1);
            }
        }
        return ans;
    }
};