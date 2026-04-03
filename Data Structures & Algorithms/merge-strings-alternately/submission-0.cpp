class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int i = 0, j = 0;
        while (i < word1.size()) {
            word1.insert(i + 1, 1, word2[j++]);
            if (j >= n2) {
                break;
            }
            i += 2;
        }
        if (j < n2) {
            word1.append(word2.substr(j));
        }
        return word1;
    }
};

// Brute Force, time: O(n), space: O(1)