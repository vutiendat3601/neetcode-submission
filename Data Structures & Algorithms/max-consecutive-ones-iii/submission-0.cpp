class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, cnt = 0, ans = 0;
        queue<int> q;
        while (r < n) {
            if (!nums[r]) cnt++, q.push(r);
            if (cnt > k) cnt--, l = q.front() + 1, q.pop();
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};