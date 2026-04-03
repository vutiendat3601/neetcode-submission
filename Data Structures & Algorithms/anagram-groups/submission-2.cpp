class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;
        
        for (string str : strs) {
            vector<int> cnts(26, 0);
            for (char c : str) {
                cnts[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                if (cnts[i]) {
                    key+= ((char) ('a' + i)) + to_string(cnts[i]);
                }
            }
            m[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto e : m) {
            ans.push_back(e.second);
        }
        return ans;
    }
};

// Map, O(max_length(strs))