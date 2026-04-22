class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> idx;
        int n = fruits.size(), l = 0, r = 0, ans = 0;
        int i1 = 0, i2 = i1;
        idx[i1] = 0;
        while (r < n) {
            if (fruits[r] != i1 && fruits[r] != i2) {
                l = max(idx[i1], idx[i2]);
                i1 = fruits[l], i2 = fruits[r], idx[fruits[r]] = r;
            }
            if (fruits[r] != fruits[r ? r - 1 : 0])
                idx[fruits[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};