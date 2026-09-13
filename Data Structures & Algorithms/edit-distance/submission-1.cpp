class Solution {
   private:
    string word1, word2;
    int m, n;
    int dfs(int k1, int k2, vector<vector<int>>& cache) {
        int i = k1 + k2;
        if (k1 >= m) return n - k2;
        if (k2 >= n) return m - k1;
        if (cache[k1][k2] < 0) {
            if (word1[k1] == word2[k2])
                cache[k1][k2] = dfs(k1 + 1, k2 + 1, cache);
            else
                cache[k1][k2] = 1 + min(dfs(k1 + 1, k2, cache),
                                        min(dfs(k1, k2 + 1, cache), dfs(k1 + 1, k2 + 1, cache)));
        }
        return cache[k1][k2];
    }

   public:
    int minDistance(string word1, string word2) {
        this->word1 = word1, this->word2 = word2;
        m = word1.size(), n = word2.size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(0, 0, cache);
    }
};
