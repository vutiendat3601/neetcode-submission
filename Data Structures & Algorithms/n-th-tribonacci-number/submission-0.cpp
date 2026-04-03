class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribo = {0, 1, 1};
        if (n < 3) {
            return tribo[n];
        }
        int i = 3;
        while (i <= n) {
            int next = tribo[0] + tribo[1] + tribo[2];
            tribo[0] = tribo[1];
            tribo[1] = tribo[2];
            tribo[2] = next;
            i++;
        }
        return tribo[2];
    }
};

// Dynamic programming, time: O(n), space: O(1)