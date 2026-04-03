class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / m;
            int c = mid % m;
            if (matrix[r][c] < target) {
                left = mid + 1;
            } else if (matrix[r][c] > target) {
                right = mid - 1;
            } else {
                return 1;
            }
        }
        return 0;
    }
};

// Binary Search, O(log(n.m))