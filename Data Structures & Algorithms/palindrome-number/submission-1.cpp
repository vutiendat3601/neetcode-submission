class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        string x_str = to_string(x);
        return stoll(string(x_str.rbegin(), x_str.rend())) == x;
    }
};