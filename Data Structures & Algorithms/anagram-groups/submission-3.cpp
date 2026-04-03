class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<bool> processed(n, 0);
        int k = 0;
        while (1) {
            while (k < n && processed[k]) {
                k++;
            }
            if (k == n) {
                break;
            }
            vector<string> res;
            res.push_back(strs[k]);
            string des(strs[k].begin(), strs[k].end());
            sort(des.begin(), des.end());
            for (int i = k + 1; i < n; i++) {
                if (!processed[i]) {
                    string tmp(strs[i].begin(), strs[i].end());
                    sort(tmp.begin(), tmp.end());
                    if (tmp == des) {
                        res.push_back(strs[i]);
                        processed[i] = 1;
                    }
                }
            }
            ans.push_back(res);
            processed[k] = 1;
        }
        return ans;
    }
};