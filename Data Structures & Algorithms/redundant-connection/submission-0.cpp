class Solution {
private:
    bool dfs(int k, int p, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[k] = 1;
        for (auto& node : adj[k]) {
            if (node != p) {
                if (visited[node])
                    return 1;
                else
                    dfs(node, k, adj, visited);
            }
        }
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            auto u = e[0], v = e[1];
            adj[u].push_back(v), adj[v].push_back(u);
            vector<bool> visited(n, 0);
            if (dfs(u, -1, adj, visited))
                return e;
        }
        return {};
    }
};
