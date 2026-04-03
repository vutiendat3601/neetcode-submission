class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), ans = 0;
        vector<bool> carried(n);
        for (int i = 0; i < n; i++) {
            if (!carried[i]) {
                int last_idx = -1;
                for (int j = i + 1; j < n; j++) {
                    if (!carried[j]) {
                        int sum = people[i] + people[j];
                        if (sum <= limit &&
                            sum > people[i] +
                                      (last_idx > -1 ? people[last_idx] : 0)) {
                            last_idx = j;
                        }
                    }
                }
                carried[i] = 1;
                if (last_idx > -1) {
                    carried[last_idx] = 1;
                }
                ans++;
            }
        }
        return ans;
    }
};

// Brute Force, time: O(n^2), space: O(n)