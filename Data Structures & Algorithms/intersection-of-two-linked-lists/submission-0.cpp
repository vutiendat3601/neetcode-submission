/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* h1, ListNode* h2) {
        ListNode *n1 = h1, *n2 = h2;
        while (n1 != n2) {
            n1 = n1 ? n1->next : h2;
            n2 = n2 ? n2->next : h1;
        }
        return n1;
    }
};