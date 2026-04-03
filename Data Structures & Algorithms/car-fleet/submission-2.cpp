class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 0;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {position[i], speed[i]};
        }
        sort(pairs.rbegin(), pairs.rend());
        stack<double> upper_times;
        upper_times.push(0); // dummy
        for (auto p : pairs) {
            double time = (double) (target - p.first) / p.second;
            if (time > upper_times.top()) {
                upper_times.push(time);
            }
        }
        return upper_times.size() - 1;
    }
};

// Stack, Sorting, O(n.log(n))
