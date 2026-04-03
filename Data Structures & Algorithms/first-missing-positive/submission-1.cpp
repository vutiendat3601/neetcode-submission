class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for (auto& num : nums) {
            if (num > 0) {
                s.insert(num);
            }
        }
        for (int i = 1; i <= INT_MAX; i++) {
            if (!s.count(i)) {
                return i;
            }
        }
        return 1;
    }
};

// Sorted Set, time: O(n), space: O(n)