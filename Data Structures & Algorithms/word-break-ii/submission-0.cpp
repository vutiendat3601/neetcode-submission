class Solution {
private:
    vector<string> ans;
    string ans_item, s;
    unordered_set<string> words;
    int n;

    void backtrack(int k) {
        if (k >= n) {
            ans.push_back(ans_item.substr(0, ans_item.size() - 1));
            return;
        }
        for (int i = 1; i <= n - k; i++) {
            string tmp = s.substr(k, i);
            if (words.count(tmp)) {
                int sz = ans_item.size();
                ans_item += tmp + " ";
                backtrack(k + i);
                ans_item.resize(sz);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s, n = s.size(), words = unordered_set<string>(wordDict.begin(), wordDict.end());
        backtrack(0);
        return ans;
    }
};