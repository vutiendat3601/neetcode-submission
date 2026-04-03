class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, mx = 0, ans = 0;
        unordered_map<char, int> cnt;
        unordered_map<int, int> cnt_eq;

        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
            cnt_eq[cnt[s[i]]]++;
            mx = max(mx, cnt[s[i]]);
            if (mx + k < (i - l + 1)) {
                cnt_eq[mx]--;
                cnt[s[l]]--;
                l++;
                if (!cnt_eq[mx]) {
                    mx--;
                }
            }
            ans = max(ans, (i - l + 1));
        }
        return ans;
    }
};