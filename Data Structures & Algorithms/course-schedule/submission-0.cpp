class Solution {
private:
    int n;
    vector<vector<int>> prereqs;
    vector<bool> visited, finished;
    bool dfs(int k) {
        visited[k] = 1;
        for (auto& i : prereqs[k]) {
            if (visited[i]) {
                if (!finished[i])
                    return 0;
            } else {
                if (!dfs(i))
                    return 0;
            }
        }
        return (finished[k] = 1);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        prereqs.assign(n, vector<int>());
        visited.assign(n, 0);
        finished.assign(n, 0);
        for (auto pre : prerequisites)
            prereqs[pre[0]].push_back(pre[1]);
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                if (!finished[i])
                    return 0;
            } else {
                if (!dfs(i))
                    return 0;
            }
        }
        return 1;
    }
};
