class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), ans = INT_MAX;
        sort(piles.begin(), piles.end());
        int bl = 1, br = piles[n - 1];
        while (bl <= br) {
            int mid = bl + (br - bl) / 2;
            auto ub = upper_bound(piles.begin(), piles.end(), mid);
            auto ub_idx = ub - piles.begin();
            int res = ub_idx;
            while (ub_idx < n) {
                res += (piles[ub_idx] + mid - 1) / mid;
                if (res > h) {
                    break;
                }
                ub_idx++;
            }
            if (res <= h) {
                br = mid - 1;
                ans = min(ans, mid);
            } else if (res > h) {
                bl = mid + 1;
            }
        }
        return ans;
    }
};