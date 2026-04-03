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
    bool isPalindrome(ListNode* head) {
        ListNode* fs  = head, *sl =head;
        stack<int> st;
        while (fs && fs->next) {
            st.push(sl->val);
            sl = sl->next;
            fs = fs->next->next;
        }
        if (fs) {
            sl=sl->next;
        }
        while (sl) {
            if (sl->val != st.top()) {
                return 0;
            }
            st.pop();
            sl = sl->next;
        }
        return 1;
    }
};