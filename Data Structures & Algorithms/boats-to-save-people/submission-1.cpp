class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), l = 0, r = n - 1, ans = 0;
        sort(people.begin(), people.end());
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