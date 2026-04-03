class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> res;

        for (string str : strs) {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            res[tmp].push_back(str);
        }
        
        for (auto p : res) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
