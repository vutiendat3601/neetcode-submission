class Solution {
   private:
    vector<int> parent;
    int ans;

    int find(int u) { return u == parent[u] ? u : (parent[u] = find(parent[u])); }

    bool unite(int u, int v) {
        u = find(u), v = find(v), parent[u] = v;
        if (u != v) ans--;
        return u == v;
    }

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n), ans = n;
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) unite(e[0], e[1]);
        return ans;
    }
};
