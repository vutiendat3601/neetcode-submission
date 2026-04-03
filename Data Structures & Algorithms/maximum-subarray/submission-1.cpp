class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, tmp_ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int addition = max(tmp_ans, 0);
            tmp_ans = nums[i] + addition;
            ans = max(ans, tmp_ans);
        }
        return ans;
    }
};

