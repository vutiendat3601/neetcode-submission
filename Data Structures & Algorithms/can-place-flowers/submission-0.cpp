class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return 1;
        int sz = flowerbed.size();

        for (int i = 0; i < sz; i++) {
            bool ok = !flowerbed[i] && (i ? !flowerbed[i - 1] : 1) && (i < sz - 1 ? !flowerbed[i + 1] : 1);
            if (ok) {
                flowerbed[i] = ok, n--;
                if (!n)
                    return 1;
            }
        }
        return 0;
    }
};