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
        ListNode *sl = head, *fs = sl;
        while (fs != nullptr && fs->next != nullptr) {
            sl = sl->next;
            fs = fs->next->next;
            if (sl == fs) {
                return 1;
            }
        }
        return 0;
    }
};
