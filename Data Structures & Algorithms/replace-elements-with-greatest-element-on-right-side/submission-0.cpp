class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), mx = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n-2;i>=0;i--) {
            int last_mx = mx;
            mx=max(arr[i], mx);
           arr[i] = last_mx;
        }
        return arr;
    }
};