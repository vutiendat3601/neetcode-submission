class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, num1 = INT_MIN, num2 = INT_MIN;
        vector<int> ans;
        for (auto& num : nums) {
            if (num1 == num) {
                cnt1++;
            } else if (num2 == num) {
                cnt2++;
            } else if (!cnt1) {
                num1 = num;
                cnt1 = 1;
            } else if (!cnt2) {
                num2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (auto& num : nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            }
        }
        if (cnt1 > n / 3) {
            ans.push_back(num1);
        }
        if (cnt2 > n / 3) {
            ans.push_back(num2);
        }
        return ans;
    }
};

// Boyer-Moore Voting Algorithm, time: O(n), space: O(1)