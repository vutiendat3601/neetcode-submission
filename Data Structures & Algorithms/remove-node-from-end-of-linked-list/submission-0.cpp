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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = new ListNode(-1, head), *dump = tmp;
        int sz = size(head), i = 0;
        n = sz - n;
        while (i < n) {
            tmp = tmp->next;
            i++;
        }
        if (tmp->next != nullptr) {
            if (tmp->next == dump->next) {
                tmp->next = tmp->next->next;
                dump->next = tmp->next;
            } else {
                tmp->next = tmp->next->next;
            }
        }
        return dump->next;
    }

    int size(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans++;
            head = head->next;
        }
        return ans;
    }
};
