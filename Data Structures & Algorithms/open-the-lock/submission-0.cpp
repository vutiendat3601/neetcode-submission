class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int k, LEN = 4, ans = 0;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000"))
            return -1;
        queue<string> q;
        visited.insert("0000"), q.push("0000");
        while (k = q.size()) {
            while (k--) {
                auto key = q.front();
                q.pop();
                if (key == target)
                    return ans;
                vector<string> next_keys;
                string tmp(key.begin(), key.end());
                for (int i = 0; i < LEN; i++) {
                    const char last = tmp[i];
                    if (last == '0') {
                        tmp[i] = '9', next_keys.push_back(tmp), tmp[i] = last;
                        tmp[i] = last + 1, next_keys.push_back(tmp), tmp[i] = last;
                    } else if (last == '9') {
                        tmp[i] = '0', next_keys.push_back(tmp), tmp[i] = last;
                        tmp[i] = last - 1, next_keys.push_back(tmp), tmp[i] = last;
                    } else {
                        tmp[i] = last - 1, next_keys.push_back(tmp), tmp[i] = last;
                        tmp[i] = last + 1, next_keys.push_back(tmp), tmp[i] = last;
                    }
                }
                for (auto nk : next_keys)
                    if (!visited.count(nk))
                        visited.insert(nk), q.push(nk);
            }
            ans++;
        }
        return -1;
    }
};