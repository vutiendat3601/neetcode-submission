class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num)) {
                return 1;
            }
            s.insert(num);
        }
        return 0;
    }
};

// Hash using Set, O(n)