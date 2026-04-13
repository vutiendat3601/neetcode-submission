class Solution {
private:
    int n, len;
    vector<int> matchsticks, sides = vector<int>(4, 0);

    bool backtrack(int i) {
        if (i == n)
            return 1;
        for (int j = 0; j < 4; j++) {
            if (sides[j] + matchsticks[i] <= len) {
                sides[j] += matchsticks[i];
                if (backtrack(i + 1))
                    return 1;
                sides[j] -= matchsticks[i];
            }
            if (!sides[j])
                break;
        }
        return 0;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        this->matchsticks = matchsticks;
        int sum = 0;
        for (auto &m : matchsticks)
            sum += m;
        if (sum % 4)
            return 0;
        n = matchsticks.size(), len = sum / 4;
        return backtrack(0);
    }
};