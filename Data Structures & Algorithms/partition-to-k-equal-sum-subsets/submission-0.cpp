class Solution {
private:
    int n, k, target;
    vector<int> nums, partition;

    bool backtrack(int i) {
        if (i == n)
            return 1;
        for (int j = 0; j < k; j++) {
            if (partition[j] + nums[i] <= target) {
                partition[j] += nums[i];
                if (backtrack(i + 1))
                    return 1;
                partition[j] -= nums[i];
            }
            if (!partition[j])
                break;
        }
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k)
            return 0;
        sort(nums.begin(), nums.end());
        this->nums = nums, this->k = k, target = sum / k, n = nums.size(), partition = vector<int>(k, 0);
        return backtrack(0);
    }
};