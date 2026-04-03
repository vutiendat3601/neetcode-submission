class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), ans = 0;
        vector<int> bound_left(n), bound_right(n);
        stack<int> st1, st2;
        for (int i = 0; i < n; i++) {
            bound_left[i] = i;
            while (!st1.empty() && h[st1.top()] >= h[i]) {
                bound_left[i] = bound_left[st1.top()];
                st1.pop();
            }
            st1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            bound_right[i] = i;
            while (!st2.empty() && h[st2.top()] >= h[i]) {
                bound_right[i] = bound_right[st2.top()];
                st2.pop();
            }
            st2.push(i);
            ans = max(ans, (bound_right[i] - bound_left[i] + 1) * h[i]);
        }
        return ans;
    }
};

// Stack, O(n)