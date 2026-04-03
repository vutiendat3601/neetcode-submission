class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto& c : s) {
            if (c == '[' || c == '{' || c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return 0;
                }
                char top = st.top();
                if ((top == '[' && c == ']') || (top == '{' && c == '}') ||
                    (top == '(' && c == ')')) {
                    st.pop();
                } else {
                    return 0;
                }
            }
        }

        return st.empty();
    }
};