class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), j = 0;
        for (auto& c : t) {
            if (c == s[j]) {
                j++;
            }
            if (j >= n) {
                break;
            }
        }
        return j >= n;
    }
};

// m = s.size(), n = t.size()
// 2-pointers, time: O(max(m, n)), space: O(1)