class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 0, last = INT_MIN;
        for (int num : nums) {
            if (num != last) {
                nums[k++] = num;
                last = num;
            }
        }
        return k;
    }
};