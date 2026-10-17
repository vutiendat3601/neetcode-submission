typedef long long ll;

class Solution {
private:
    ll getSum(vector<ll>& prefix, int a, int b) {
        if (a)
            return prefix[b] - prefix[a - 1];
        return prefix[b];
    }
public:
    ll maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefix(n, 0);
        prefix[0] = nums[0];
        ll ans = INT_MIN;
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        for (int i = 0; i < n; i++)
            ans = max(ans, max(getSum(prefix, 0, i), getSum(prefix, i, n - 1)));
        return ans;
    }
};
