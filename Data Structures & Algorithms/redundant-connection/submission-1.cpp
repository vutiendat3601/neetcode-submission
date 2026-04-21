class Solution {
private:
    vector<int> parent;
    int find(int u) {
        return u == parent[u] ? u : (parent[u] = find(parent[u]));
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        parent[v] = u;
        return u == v;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1), iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges)
            if (unite(e[0], e[1]))
                return e;
        return {};
    }
};
