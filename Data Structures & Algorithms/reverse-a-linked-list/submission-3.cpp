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
        ListNode* tail = nullptr;
        while (head) {
            ListNode* next_head = head->next;
            head->next = tail;
            tail = head;
            head = next_head;
        }
        return tail;
    }
};

// Iteration, time: O(n), space: O(1)