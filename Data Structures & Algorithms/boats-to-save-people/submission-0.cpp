class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), ans = 0;
        sort(people.begin(), people.end());
        int l = 0, r = n - 1;
        while (l <= r) {
            if (people[r] + people[l] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            ans++;
        }
        return ans;
    }
};

// 2-pointers, time: O(n.log(n)), space: O(1)