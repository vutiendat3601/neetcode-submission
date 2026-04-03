class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for (auto& c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            if (cnt[c - 'a']) {
                cnt[c - 'a']--;
            } else {
                return 0;
            }
        }
        return 1;
    }
};