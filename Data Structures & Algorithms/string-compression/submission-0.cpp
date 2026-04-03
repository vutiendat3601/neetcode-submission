class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), j = -1, cnt = 1;
        char last = chars[0];
        for (int i = 1; i < n; i++) {
            if (last == chars[i]) {
                cnt++;
            } else {
                chars[++j] = last;
                if (cnt > 1) {
                    string zz = to_string(cnt);
                    for (int z = 0; z < zz.size(); z++) {
                        chars[++j] = zz[z];
                    }
                }
                cnt = 1;
            }
            last = chars[i];
        }
        chars[++j] = last;
        if (cnt > 1) {
            string zz = to_string(cnt);
            for (int z = 0; z < zz.size(); z++) {
                chars[++j] = zz[z];
            }
        }
        return j + 1;
    }
};