class Solution {
private:
    unordered_set<string> signs = {"+", "-", "*", "/"};
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size(), ans = 0, a = 0, b = 0, res = 0;
        for (string & token : tokens) {
            if (signs.count(token)) {
                b = st.top();st.pop();
                a = st.top(); st.pop();
                if (token == "+") {
                    res = a + b;
                } else if (token == "-") {
                    res = a - b;
                } else if (token == "*") {
                    res = a * b;
                } else if (token == "/") {
                    res = a/ b;
                }
                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

// Stack, O(n)
