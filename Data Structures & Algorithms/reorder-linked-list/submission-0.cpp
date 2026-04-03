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
    void reorderList(ListNode* head) {
        ListNode *sl = head, *fs = sl, *mid, *tail;
        while (fs != nullptr && fs->next != nullptr) {
            sl = sl->next;
            fs = fs->next->next;
        }
        mid = sl->next;
        sl->next = nullptr;
        tail = reverseList(mid, nullptr);
        while (tail != nullptr) {
            ListNode *next_head = head->next, *next_tail = tail->next;
            head->next = tail;
            tail->next = next_head;
            head = next_head;
            tail = next_tail;
        }
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return tail;
        }
        ListNode* next_head = head->next;
        head->next = tail;
        ListNode* next_tail = head;
        return reverseList(next_head, next_tail);
    }
};
