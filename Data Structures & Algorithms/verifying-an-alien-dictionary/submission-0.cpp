class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> idx;
        for (int i = 0; i < order.size(); i++)
            idx[order[i]] = i;
        vector<string> w(words.begin(), words.end());
        sort(w.begin(), w.end(), [&](string a, string b) {
            int i = 0;
            while (i  < a.size() && i < b.size()) {
                if (a[i] != b[i])
                    return idx[a[i]] < idx[b[i]];
                i++;
            }
            return a.size() < b.size();
        });
        for (int i = 0; i < words.size(); i++)
            if (words[i] != w[i])
                return 0;
        return 1;
    }
};