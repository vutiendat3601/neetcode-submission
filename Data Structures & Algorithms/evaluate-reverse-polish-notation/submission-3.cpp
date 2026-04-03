class Solution {
private:
    unordered_set<string> signs = {"+", "-", "*", "/"};
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        int a = 0, b = 0, res = 0;
        while (tokens.size() > 1) {
            for (int i = 2; i < tokens.size(); i++) {
                if (signs.count(tokens[i])) {
                    a = stoi(tokens[i-2]), b = stoi(tokens[i-1]);
                    if (tokens[i] == "+") {
                        res = a + b;
                    } else if (tokens[i] == "-") {
                        res = a - b;
                    } else if (tokens[i] == "*") {
                        res = a * b;
                    } else if (tokens[i] == "/") {
                        res = a / b;
                    }
                    tokens[i] = to_string(res);
                    tokens.erase(tokens.begin() + (i - 2), tokens.begin() + i);
                    break;
                }
            }
        }
        ans = stoi(tokens[0]);
        return ans;
    }
};

// Brute Force, O(n^2)