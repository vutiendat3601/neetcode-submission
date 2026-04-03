class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        return numDecodings(s, n, 0);
    }

    int numDecodings(string s, const int n, int k) {
        if (k >= n) {
            return 1;
        }
        if (s[k] == '0') {
            return 0;
        }
        int ans = numDecodings(s, n, k + 1);
        if (k + 1 < n && stoi(s.substr(k, 2)) <= 26) {
            ans += numDecodings(s, n, k + 2);
        }
        return ans;
    }
};

// DFS, time: O(2^n), space: O(2^n)