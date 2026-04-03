class Solution {
private:
    unordered_set<char> open_signs = {'(', '[', '{'};
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (open_signs.count(c)) {
                st.push(c);
            } else {
                if (st.empty()) {
                    st.push(c);
                } else {
                    char top = st.top();
                    if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                }
            }
        }
        return st.empty();
    }
};
