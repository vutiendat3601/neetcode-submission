class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0, mn = 0, ans = 0;
        for (auto &num : nums) {
            mx += num;
            mn = max(mn, num);
        }
        while (mn <= mx) {
            int mid = mn + (mx - mn) / 2;
            int cnt = 1, sum = 0;
            for (auto&num:nums){
                if (sum+num<=mid){
                    sum+=num;
                }else{
                    cnt++;
                    sum=num;
                }
            }
            if (cnt <= k) {
                ans = mid;
                mx = mid - 1;
            } else {
                mn = mid + 1;
            }
        }
        return ans;
    }
};