class Solution {
   public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size(), l = 0, r = k, sum = 0, ans = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        if ((double)sum / k >= threshold) ans++;
        while (r < n) {
            sum -= nums[l++], sum += nums[r++];
            if ((double)sum / k >= threshold) ans++;
        }
        return ans;
    }
};