class Solution {
private:
    string s, ans_item = "";
    vector<string> ans;
    int n = 0, cnt = 0;

    void backtrack(int k) {
        bool k_n = k >= n, cnt_4 = cnt >= 4;
        if (k_n) {
            if (!cnt_4)
                return;
            ans.push_back(ans_item.substr(0, ans_item.size() - 1));
            return;
        }
        if (cnt_4)
            return;
        string tmp = s.substr(k, 1);
        int ans_item_size = ans_item.size();
        ans_item += tmp + ".", cnt++, backtrack(k + 1), ans_item.resize(ans_item_size), cnt--;
        for (int i = 2; i <= min(3, n - k); i++) {
            tmp = s.substr(k, i);
            if (!tmp.starts_with("0") && stoi(tmp) <= 255) {
                ans_item += tmp + ".", cnt++, backtrack(k + i), ans_item.resize(ans_item_size), cnt--;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        n = s.size();
        backtrack(0);
        return ans;
    }
};