class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), k = s1.size();
        if (k > n) {
            return 0;
        }
        sort(s1.begin(), s1.end());
        vector<int> cnt(26, 0);
        string cmp = "";
        for (int i = 0; i < k; i++) {
            cnt[s2[i] - 'a']++;
        }
        for (int z = 0; z < 26; z++) {
            cmp += string(cnt[z], char('a' + z));
        }
        if (cmp == s1) {
            return 1;
        }
        for (int i = k; i < n; i++) {
            cnt[s2[i - k] - 'a']--;
            cnt[s2[i] - 'a']++;
            cmp = "";
            for (int z = 0; z < 26; z++) {
                cmp += string(cnt[z], char('a' + z));
            }
            if (cmp == s1) {
                return 1;
            }
        }
        return 0;
    }
};