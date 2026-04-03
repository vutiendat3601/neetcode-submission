class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> s(n);
        for (int i=0; i < n; i++){
            s[i] = {nums[i], i};
        }
        sort(s.begin(), s.end());
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = s[l].first + s[r].first;
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                return {min(s[l].second, s[r].second), max(s[l].second, s[r].second)};
            }
        }
        return {};
    }
};

// Sorting, 2 pointers, O(n.log(n))