class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans = "";
        if (strs.empty()) {
            return ans;
        }
        for (string str : strs) {
            ans += to_string(str.size()) + ",";
        }
        ans += "#";
        for (string str : strs) {
            ans += str + ",";
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans = {};
        if (s == "") {
            return ans;
        }
        vector<int> sizes;
        while (s[i] != '#') {
            string sz_str = "";
            while (s[i] != ',') {
                sz_str += s[i];
                i++;
            }
            sizes.push_back(stoi(sz_str));
            i++;
        }
        i++;
        for (int sz : sizes) {
            ans.push_back(s.substr(i, sz));
            i += sz;
            i++;
        }
        return ans;
    }
};
