class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        k++;
        unordered_set<int> s;
        for (int i = 0; i < min(k, n); i++) {
            if (s.count(nums[i])) {
                return 1;
            }
            s.insert(nums[i]);
        }
        for (int i = k; i < n; i++) {
            s.erase(nums[i - k]);
            if (s.count(nums[i])) {
                return 1;
            }
            s.insert(nums[i]);
        }
        return 0;
    }
};

// Set + Sliding Window, time: O(n), space: O(n)