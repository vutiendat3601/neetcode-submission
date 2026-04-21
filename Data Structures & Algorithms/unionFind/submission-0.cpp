class UnionFind {
private:
    vector<int> parent;
    int n;
public:
    UnionFind(int n) {
        this->n = n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return find(parent[x]);
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return 0;
        parent[x] = y;
        return 1;
    }

    int getNumComponents() {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        return ans;
    }
};
