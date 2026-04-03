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
    ListNode* reverseList(ListNode* head) {
        return head == nullptr ? head : reverseList(head, nullptr);
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (head->next == nullptr) {
            head->next = tail;
            return head;
        }
        ListNode* next_head = head->next;
        head->next = tail;
        ListNode* next_tail = head;
        return reverseList(next_head, next_tail);
    }
};
