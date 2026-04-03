class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0, ans = INT_MAX;
        for (auto&w:weights){
            l = max(l, w);
            r+=w;
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int num_of_days = 1, sum = 0;
            for (auto&w:weights) {
                if (sum + w <= mid) {
                    sum+=w;
                } else {
                    num_of_days++;
                    sum = w;
                }
            }
            if (num_of_days<=days) {
                ans = min(ans, mid);
                r=mid-1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

