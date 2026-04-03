class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;
        for (auto& ast : asteroids) {
            if (ast > 0) {
                st.push(ast);
            } else {
                bool pushable = 1;
                int t = -1;
                while (!st.empty() && (t = st.top()) > 0) {
                    if (t + ast == 0) {
                        st.pop();
                        pushable = 0;
                        break;
                    }
                    if (t > abs(ast)) {
                        pushable = 0;
                        break;
                    }
                    st.pop();
                }
                if (pushable) {
                    st.push(ast);
                }
            }
        }
        ans.assign(st.size(), 0);
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};

// Stack, time: O(n), space: O(n)