class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            string des(str.begin(), str.end());
            sort(des.begin(), des.end());
            mp[des].push_back(str);
        }
        for (auto& [key, value] : mp) {
            ans.push_back(value);
        }
        return ans;
    }
};