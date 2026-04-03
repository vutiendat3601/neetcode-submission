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
    bool hasCycle(ListNode* head) {
        ListNode *fs = head, *sl = head;
        while (fs && fs->next) {
            sl = sl->next;
            fs = fs->next->next;
            if (sl == fs) {
                return 1;
            }
        }
        return 0;
    }
};

// Fast and Slow pointer, time: O(n), space: O(1)