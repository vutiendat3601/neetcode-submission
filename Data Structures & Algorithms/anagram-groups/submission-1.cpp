class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;
        
        for (string str : strs) {
            string tmp(str.begin(), str.end());
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto e : m) {
            ans.push_back(e.second);
        }
        return ans;
    }
};

// Sorting, Map, O(max_length(strs))