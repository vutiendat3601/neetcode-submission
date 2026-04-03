class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> ranks(n);
        unordered_map<int, int> cnt;
        vector<int> ans(k);
        for (auto& num : nums) {
            cnt[num]++;
        }
        int i = 0;
        for (auto& [k, v] : cnt) {
            ranks[i++] = {v, k};
        }
        sort(ranks.begin(), ranks.end());
        i = 0;
        while (i < k) {
            ans[k - 1 - i] = ranks[n - 1 - i].second;
            i++;
        }
        return ans;
    }
};