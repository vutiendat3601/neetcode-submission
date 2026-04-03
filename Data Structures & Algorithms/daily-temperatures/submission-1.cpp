class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> st, st2;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && t[i] > st.top()) {
                ans[st2.top()] = i - st2.top();
                st.pop();
                st2.pop();
            }
            st.push(t[i]);
            st2.push(i);
        }
        return ans;
    }
};

// Brute Force, O(n^2)