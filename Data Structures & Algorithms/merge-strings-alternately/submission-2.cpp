class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), i = 0, i1 = 0, i2 = 0;
        vector<char> res(n1 + n2);
        while (i1 < n1 && i2 < n2) {
            res[i++] = word1[i1++];
            res[i++] = word2[i2++];
        }
        while (i1 < n1) {
            res[i++] = word1[i1++];
        }
        while (i2 < n2) {
            res[i++] = word2[i2++];
        }
        return string(res.begin(), res.end());
    }
};

// 2-pointers, time: O(max(n, m)), space: O(1)