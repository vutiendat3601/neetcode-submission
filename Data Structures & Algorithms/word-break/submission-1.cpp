class Solution {
private:
    unordered_set<string> words;
    vector<vector<int>> cache;
    bool dfs(string s, int i, int j) {
        int n = s.size();
        if (i >= n) {
            return 1;
        }
        if (j >= n) {
            return 0;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        string w = s.substr(i, j - i + 1);
        if (words.count(w)) {
            cache[i][j] = 1;
            if (dfs(s, j + 1, j + 1)) {
                return 1;
            }
        }
        cache[i][j] = 0;
        return dfs(s, i, j + 1);
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        words = unordered_set<string>(wordDict.begin(), wordDict.end());
        cache = vector<vector<int>>(n, vector<int>(n, -1));
        return dfs(s, 0, 0);
    }
};
