class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i <= n / 2; i++) {
            if (!s.count(nums[i])) {
                int cnt = 1;
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] == nums[i]) {
                        cnt++;
                    }
                }
                if (cnt > n / 2) {
                    return nums[i];
                }
                s.insert(nums[i]);
            }
        }
        return INT_MIN;
    }
};