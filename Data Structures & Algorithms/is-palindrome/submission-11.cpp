class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> chs;
        for (auto& c : s) {
            if ('a' <= c && c <= 'z') {
                chs.push_back(c);
            } else if ('0' <= c && c <= '9') {
                chs.push_back(c);
            } else if ('A' <= c && c <= 'Z') {
                chs.push_back(c + 32);
            }
        }
        int l = 0, r = chs.size() - 1;
        while (l < r) {
            if (chs[l] != chs[r]) {
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
};

// 2-pointers, time: O(n), space: O(1)