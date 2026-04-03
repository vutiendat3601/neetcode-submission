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
    ListNode* middleNode(ListNode* head) {
        ListNode *sl = head, *fs = head;
        while (fs && fs->next) {
            sl = sl->next;
            fs = fs->next->next;
        }
        return sl;
    }
};

// Slow and Fast pointer, time: O(n), space: O(1)