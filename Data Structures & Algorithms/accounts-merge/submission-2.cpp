class Solution {
private:
    vector<unordered_set<int>> adj;
    int n;
    vector<bool> visited;
    set<string> dfs(int u, vector<vector<string>>& accounts) {
        visited[u] = 1;
        set<string> ans(accounts[u].begin() + 1, accounts[u].end());
        for (auto v : adj[u]) {
            if (!visited[v]){
                set<string> nxt = dfs(v, accounts);
                ans.insert(nxt.begin(), nxt.end());
            }
        }
        return ans;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        n = accounts.size(), adj.resize(n), visited.assign(n, 0);
        vector<vector<string>> ans;
        unordered_map<string, int> email_node;
        for (int k = 0; k < n; k++) {
            for (int i = 1; i < accounts[k].size(); i++) {
                string email = accounts[k][i];
                if (email_node.count(email)) {
                    adj[email_node[email]].insert(k);
                    adj[k].insert(email_node[email]);
                } else {
                    email_node[email] = k;
                }
            }
        }

        for (int u = 0; u < n; u++) {
            if (!visited[u]) {
                vector<string> ans_item;
                ans_item.push_back(accounts[u][0]);
                set<string> emails = dfs(u, accounts);
                ans_item.insert(ans_item.end(), emails.begin(), emails.end());
                ans.push_back(ans_item);
            }
        }

        return ans;
    }
};

// DFS