class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = arr[i];
        }
        for (int i = k; i < n; i++) {
            int a = abs(ans[0] - x), b = abs(ans[k - 1] - x), c = abs(arr[i] - x);
            if (c < b || c < a) {
                for (int j = 0; j < k - 1; j++) {
                    ans[j] = ans[j + 1];
                }
                ans[k - 1] = arr[i];
            }
        }

        return ans;
    }
};

// Sliding Window, time: O(n), space: O(n)