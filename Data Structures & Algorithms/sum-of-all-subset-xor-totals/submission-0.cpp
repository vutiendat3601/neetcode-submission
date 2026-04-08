class Solution {
private:
    int sum = 0;

    void backtrack(vector<int>& nums, int k, int _xor) {
        if (k >= nums.size()) {
            sum += _xor;
            return;
        }
        backtrack(nums, k + 1, _xor);
        backtrack(nums, k + 1, _xor ^ nums[k]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return sum;
    }
};