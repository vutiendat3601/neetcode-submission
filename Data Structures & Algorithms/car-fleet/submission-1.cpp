class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 0;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {position[i], speed[i]};
        }
        sort(pairs.rbegin(), pairs.rend());
        double prev_time = 0;
        for (auto p : pairs) {
            double time = (double) (target - p.first) / p.second;
            if (time > prev_time) {
                ans++;
                prev_time = time;
            }
        }
        return ans;
    }
};
// Sorting, O(n.log(n))
