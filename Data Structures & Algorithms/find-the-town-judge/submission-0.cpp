class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int i = n;

        while (i) {
            bool cont = 1;
            int cnt = 0;
            for (auto &t : trust) {
                if (t[0] == i) {
                    cont = 0;
                    break;
                }
                if (t[1] == i)
                    cnt++;
            }
            if (cont && cnt == n -1)
                return i;
            i--;
        }

        return -1;
    }
};