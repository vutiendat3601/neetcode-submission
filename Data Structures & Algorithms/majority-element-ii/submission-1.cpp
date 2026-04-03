class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (!s.count(nums[i])) {
                for (int j = i; j < n; j++) {
                    if (nums[i] == nums[j]) {
                        cnt++;
                    }
                    if (cnt > n / 3) {
                        ans.push_back(nums[i]);
                        break;
                    }
                }
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(1)