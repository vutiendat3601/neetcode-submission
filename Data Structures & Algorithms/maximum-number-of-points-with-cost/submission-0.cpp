typedef long long ll;
class Solution {
private:
    int m, n;
    ll dfs(int r, int c, vector<vector<int>>& points,
           vector<vector<ll>>& cache) {
        if (r >= m)
            return 0;
        if (r == m - 1)
            return points[r][c];
        if (cache[r][c] < 0) {
            cache[r][c] = 0;
            for (int i = 0; i < n; i++) {
                int offset = abs(c - i);
                cache[r][c] =
                    max(cache[r][c],
                        points[r][c] - offset + dfs(r + 1, i, points, cache));
            }
        }
        return cache[r][c];
    }

public:
    ll maxPoints(vector<vector<int>>& points) {
        m = points.size(), n = points[0].size();
        ll ans = 0;
        vector<vector<ll>> cache(m, vector<ll>(n, -1));
        for (int c = 0; c < n; c++)
            ans = max(ans, dfs(0, c, points, cache));
        return ans;
    }
};