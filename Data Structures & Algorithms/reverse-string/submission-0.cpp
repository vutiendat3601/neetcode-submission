class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};

// 2-pointers, time: O(n), space: O(1)