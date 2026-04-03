class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string ans(n1 + n2, '\0');
        int i = 0, i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            ans[i++] = word1[i1++];
            ans[i++] = word2[i2++];
        }
        while (i1 < n1) {
            ans[i++] = word1[i1++];
        }
        while (i2 < n2) {
            ans[i++] = word2[i2++];
        }
        return ans;
    }
};

// 2-pointers, time: O(n), space: O(n)