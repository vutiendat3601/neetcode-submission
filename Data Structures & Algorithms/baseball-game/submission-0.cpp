class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> points;
        for (auto& op : operations) {
            if (op == "+") {
                int a = points.top();
                points.pop();
                int b = points.top();
                points.push(a);
                points.push(a + b);
            } else if (op == "D") {
                int a = points.top();
                points.push(a * 2);
            } else if (op == "C") {
                points.pop();
            } else {
                points.push(stoi(op));
            }
        }
        int ans = 0;
        while (!points.empty()) {
            ans += points.top();
            points.pop();
        }
        return ans;
    }
};

// Stack, time: O(n), space: O(n)