class Solution {
private:
    vector<int> parent;

    int find(int u) {
        return u == parent[u] ? u : (parent[u] = find(parent[u]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        parent[v] = u;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<unordered_set<string>> node_email(n);
        for (int i = 0; i < n; i++)
            node_email[i].insert(accounts[i].begin() + 1, accounts[i].end());
        vector<pair<int, int>> edges = build_edges(node_email);
        parent.resize(n), iota(parent.begin(), parent.end(), 0);
        for (auto& [u, v] : edges)
            unite(u, v);
        vector<vector<int>> groups(n);
        for (int u = 0; u < n; u++)
            groups[find(u)].push_back(u);
        vector<vector<string>> ans;
        for (int u = 0; u < n; u++) {
            if (groups[u].size()) {
                vector<string> ans_item;
                ans_item.push_back(accounts[u][0]);
                set<string> emails;
                for (auto& gr : groups[u])
                    emails.insert(node_email[gr].begin(), node_email[gr].end());
                ans_item.insert(ans_item.end(), emails.begin(), emails.end());
                ans.push_back(ans_item);
            }
        }
        return ans;
    }

private:
    vector<pair<int, int>>
    build_edges(vector<unordered_set<string>>& node_email) {
        int n = node_email.size();
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (auto& email : node_email[i]) {
                    if (node_email[j].count(email)) {
                        edges.push_back({i, j});
                        break;
                    }
                }
            }
        }
        return edges;
    }
};

// Union Find