class Solution {
private:
    vector<vector<int>> prereqs;
    vector<bool> finished, visited;
    vector<int> ans;

    bool dfs(int k) {
        if (finished[k])
            return 1;
        if (visited[k])
            return 0;
        visited[k] = 1;

        for (auto& i : prereqs[k]) {
            if (visited[i]) {
                if (!finished[i])
                    return 0;
            } else if (!dfs(i)) {
                return 0;
            }
        }

        ans.push_back(k);
        return (finished[k] = 1);
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        prereqs.assign(n, vector<int>());
        for (auto& pre : prerequisites) {
            prereqs[pre[0]].push_back(pre[1]);
        }
        visited.assign(n, 0);
        finished.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!dfs(i))
                return {};
        }
        return ans;
    }
};
