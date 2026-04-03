class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size(), ans = 0;
        for (auto &d:details) {
            if (stoi(d.substr(11,2)) > 60) {
ans++;
            }
        }
        return ans;
    }
};