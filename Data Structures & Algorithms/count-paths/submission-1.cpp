class Solution {
private:
    int dfs(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        return dfs(m - 1, n) + dfs(m, n - 1);
    }
public:
    int uniquePaths(int m, int n) {
        return dfs(m, n);
    }
};

// DFS, time: O(max(m, n)), space: O(max(m, n))