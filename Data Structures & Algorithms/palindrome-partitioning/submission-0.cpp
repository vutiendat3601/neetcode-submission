class Solution {
private:
    string s;
    int n;
    vector<vector<string>> ans;
    vector<string> ans_item;

    bool is_palindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[n - 1 - i])
                return 0;
        return 1;
    }

    void backtrack(int k) {
        if (k >= n) {
            ans.push_back(ans_item);
            return;
        }
        
        for (int i = 1; i <= n - k; i++) {
            string tmp = s.substr(k, i);
            if (is_palindrome(tmp))
                ans_item.push_back(tmp), backtrack(k + i), ans_item.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();
        backtrack(0);
        return ans;
    }
};
