class Solution {
public:
    string decodeString(string s) {
        int n = s.size(), i = 0;
        stack<string> st;

        while (i < n) {
            string cur = "";
            if (isdigit(s[i])) {
                cur += s[i];
                while (i + 1 < n && isdigit(s[i + 1])) {
                    i++;
                    cur += s[i];
                }
                st.push(cur);
            } else if (s[i] == ']') {
                string copy = st.top(), add = "";
                st.pop();
                int num_of_copy = stoi(st.top());
                st.pop();
                for (int j = 0; j < num_of_copy; j++) {
                    add += copy;
                }
                if (st.empty() || isdigit(st.top()[0])) {
                    st.push(add);
                } else {
                    string top = st.top();
                    st.pop();
                    top += add;
                    st.push(top);
                }
            } else if (s[i] != '[') {
                cur += s[i];
                while (i + 1 < n && !isdigit(s[i + 1]) && s[i + 1] != '[' &&
                       s[i + 1] != ']') {
                    i++;
                    cur += s[i];
                }
                if (st.empty() || isdigit(st.top()[0])) {
                    st.push(cur);
                } else {
                    string top = st.top();
                    st.pop();
                    top += cur;
                    st.push(top);
                }
            }
            i++;
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// Stack, time: O(n), space: O(n)