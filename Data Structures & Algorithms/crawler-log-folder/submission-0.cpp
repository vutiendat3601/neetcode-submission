class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto & log: logs) {
            if (log == "../") {
                ans = ans ? ans - 1 : ans;
            } else if (log != "./") {
                ans++;
            }
        }
        return ans;
    }
};