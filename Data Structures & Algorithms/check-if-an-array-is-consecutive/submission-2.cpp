class Solution {
   public:
    bool isConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int last = nums[0] - 1;
        for (auto& num : nums) {
            if (num != last + 1)
                return 0;
            else
                last = num;
        }
        return 1;
    }
};
