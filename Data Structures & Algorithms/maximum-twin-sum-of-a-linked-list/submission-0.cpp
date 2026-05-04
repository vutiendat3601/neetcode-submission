/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int i = -1, ans = 0;
        vector<int> nums;
        ListNode *sl = head, *fs = head;
        while (fs && fs->next) {
            i++;
            nums.push_back(sl->val);
            sl = sl->next;
            fs = fs->next->next;
        }
        while (sl) {
            ans = max(ans, nums[i--] + sl->val);
            sl = sl->next;
        }
        return ans;
    }
};

// n is even
// Slow and Fast pointer, time: O(n), space: O(n)