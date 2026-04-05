class Solution {
private:
    unordered_map<int, vector<int>> tree;
    vector<bool> hasApple, visited;
    int ans = 0;
    
    int dfs(int v) {
        visited[v] = 1;
        int numOfApples = hasApple[v] ? 1 : 0;

        for (const auto & c : tree[v]) {
            if (!visited[c]) {
                auto a = dfs(c);
                if (a) {
                    numOfApples += a;
                    ans += 2;
                }
            }
        }

        return numOfApples;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->hasApple = hasApple;
        this->visited = vector<bool>(n, 0);
        for (auto &edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        return ans;
    }
};