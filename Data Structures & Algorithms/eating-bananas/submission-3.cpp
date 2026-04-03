class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), ans = INT_MAX;
        sort(piles.begin(), piles.end());
        
        int l = 1, r = piles[n - 1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<int>::iterator ub = upper_bound(piles.begin(), piles.end(), mid);
            int res = ub - piles.begin();
            while (ub != piles.end()) {
                res += (*ub + mid - 1) / mid;
                if (res > h) {
                    break;
                }
                ub++;
            }
            if (ub == piles.end()) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
