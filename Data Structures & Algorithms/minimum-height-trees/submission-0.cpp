class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
            degree[e[0]]++, degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                q.push(i);
        
        int remain = n;
        while (remain > 2) {
            int k = q.size();
            remain -= k;
            while (k--) {
                auto u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    degree[v]--;
                    if (degree[v] == 1)
                        q.push(v);
                }
            }
        }
        vector<int> ans;
        while (q.size())
            ans.push_back(q.front()), q.pop();
        return ans;
    }
};