class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size(), ans = 0;
        char last = s[0];
        for (auto& c : s) {
            ans += abs(c - last);
            last = c;
        }
        return ans;
    }
};