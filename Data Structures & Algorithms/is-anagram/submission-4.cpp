class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) {
            return 0;
        }
        vector<int> cnts(26, 0);
        for (int i = 0; i < n; i++) {
            cnts[s[i]-'a']++;
            cnts[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnts[i]) {
                return 0;
            }
        }
        return 1;
    }
};

// Hashing 26 buckets