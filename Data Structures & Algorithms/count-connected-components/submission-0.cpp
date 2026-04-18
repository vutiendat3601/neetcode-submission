class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> adj;
    void dfs(int u) {
        visited[u] = 1;
        for (auto& v : adj[u])
            if (!visited[v])
                dfs(v);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        visited.assign(n, 0), adj.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int u = 0; u < n; u++) {
            if (!visited[u])
                dfs(u), ans++;
        }
        return ans;
    }
};
