class Solution {
public:
    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += to_string(strs[i].size()) + " ";
        }
        ans += "#";
        for (int i = 0; i < n; i++) {
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        stringstream ss(s);
        string pref = "", suff = "", t = "";
        getline(ss, pref, '#');
        getline(ss, suff, '\n');
        ss = stringstream(pref);

        int z = 0, i = 0;
        while (ss >> t) {
            z = stoi(t);
            ans.push_back(suff.substr(i, z));
            i += z;
        }
        return ans;
    }
};
