class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size(), j = 0;
        for (auto &c:s) {
            if (c == t[j]) {
                j++;
            }
            if (j >= t.size()) {
                break;
            }
        }
        return t.size() - j;
    }
};