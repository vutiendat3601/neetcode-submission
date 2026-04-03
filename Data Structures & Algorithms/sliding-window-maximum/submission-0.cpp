class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), j = 0;
        vector<int> ans(n - (k - 1), 0);
        map<int, int> cnt;
        for (int i = 0; i < k; i++) {
            cnt[nums[i]]++;
        }
        ans[j++] = cnt.rbegin()->first;
        for (int i = k; i < n; i++) {
            cnt[nums[i - k]]--;
            if (!cnt[nums[i - k]]) {
                cnt.erase(nums[i - k]);
            }
            cnt[nums[i]]++;
            ans[j++] = cnt.rbegin()->first;
        }
        return ans;
    }
};

// Sorted Map, time: O(n), space: O(k)