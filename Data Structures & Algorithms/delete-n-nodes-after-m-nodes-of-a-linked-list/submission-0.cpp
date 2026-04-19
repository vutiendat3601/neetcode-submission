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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* prev = head, *oh = head;
        int i = m, j = n;
        while (head) {
            if (i) {
                i--;
                prev = head;
                head = head->next;
                if (!i)
                    prev->next = nullptr;
            } else {
                if (j) {
                    j--;
                    head = head->next;
                }
                if (!j) {
                    prev->next = head;
                    i = m, j = n;
                }
            }
        }
        return oh;
    }
};
