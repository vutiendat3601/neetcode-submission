class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(), m = abbr.size(),  i = 0,j = 0;
        while (i < n && j < m) {
            if (abbr[j] == word[i]) {
                i++;
                j++;
            } else {
                if (isalpha(abbr[j]) || !(abbr[j] - '0')) {
                    return 0;
                }
                int skip = 0;
                while (j < m && isdigit(abbr[j])) {
                    skip *= 10;
                    skip += abbr[j] - '0';
                    j++;
                }
                i += skip;
            }
        }
        return i == n && j == m;
    }
};