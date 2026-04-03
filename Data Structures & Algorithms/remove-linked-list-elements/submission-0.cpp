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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(), *node = dummy;
        while (head) {
            if (head->val != val) {
                node->next = head;
                node = node->next;
            }
            head = head->next;
            node->next = nullptr;
        }
        return dummy->next;
    }
};

// 2-pointers, time: O(n), space: O(1)