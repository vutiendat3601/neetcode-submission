class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            ans[(i + k) % n] = nums[i];
            i++;
        }
        
        i = 0;
        while (i < n) {
            nums[i] = ans[i];
            i++;
        }
    }
};
