typedef long long ll;
class Solution {
private:
    ll getSum(vector<ll>& pref, int a, int b) {
        return a ? pref[b] - pref[a - 1] : pref[b];
    }
public:
    ll maximumSumScore(vector<int>& nums) {
        ll ans = INT_MIN;
        int n = nums.size();
        vector<ll> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];
        for (int i = 0; i < n; i++)
            ans = max(getSum(pref, 0, i), getSum(pref, i, n - 1));
        return ans;
    }
};
