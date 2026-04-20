class Solution {
private:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, double> res;

    double dfs(string u, string& des, unordered_set<string>& visited) {
        if (u == des)
            return 1.0;
        visited.insert(u);
        for (auto& v : adj[u]) {
            if (!visited.count(v)) {
                string key = u + "/" + v;
                double product = res[key] * dfs(v, des, visited);
                if (product >= 0)
                    return product;
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            string key = a + "/" + b, rev_key = b + "/" + a;
            adj[a].push_back(b), adj[b].push_back(a);
            res[key] = values[i], res[rev_key] = 1.0 / values[i];
        }
        vector<double> ans;
        for (auto& q : queries) {
            string a = q[0], b = q[1];
            if (adj.count(a) && adj.count(b)) {
                unordered_set<string> visited;
                ans.push_back(dfs(a, b, visited));
            } else {
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};