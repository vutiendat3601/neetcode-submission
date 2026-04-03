class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        k++;
        unordered_map<int, int> cnt;
        for (int i = 0; i < min(k, n); i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1) {
                return 1;
            }
        }
        for (int i = k; i < n; i++) {
            cnt[nums[i - k]]--;
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1) {
                return 1;
            }
        }
        return 0;
    }
};

// Map + Sliding Window, time: O(n), space: O(n)