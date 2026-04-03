class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            int j = 0;
            while (j < strs[i].size()) {
                if (j >= ans.size() || strs[i][j] != ans[j]) {
                    break;
                }
                j++;
            }
            ans = strs[i].substr(0, j);
        }
        return ans;
    }
};