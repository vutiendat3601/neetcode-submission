class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        queue<int> q;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        for (int i = k; i < n; i++) {
            int a = abs(q.front() - x), b = abs(q.back() - x), c = abs(arr[i] - x);
            if (c < b || c < a) {
                q.pop();
                q.push(arr[i]);
            }
        }
        int z = 0;
        while (!q.empty()) {
            ans[z++] = q.front();
            q.pop();
        }
        return ans;
    }
};

// Sliding Window + Queue, time: O(n), space: O(n)