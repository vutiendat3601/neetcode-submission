class Solution {
private:
    vector<unordered_set<int>> reqs;
    vector<vector<int>> gr;
    vector<bool> visited;

    unordered_set<int> dfs(int k) {
        visited[k] = 1;
        for (auto& ch : gr[k]) {
            unordered_set<int> deps = reqs[ch];
            if (!visited[ch])
                deps = dfs(ch);
            reqs[k].insert(deps.begin(), deps.end());
        }
        reqs[k].insert(k);
        return reqs[k];
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pr, vector<vector<int>>& qu) {
        reqs.resize(n), gr.resize(n), visited.resize(n);
        vector<bool> ans;
        for (auto& p : pr)
            gr[p[1]].push_back(p[0]);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i);
        for (auto& q : qu)
            ans.push_back(reqs[q[1]].count(q[0]));
        return ans;
    }
};