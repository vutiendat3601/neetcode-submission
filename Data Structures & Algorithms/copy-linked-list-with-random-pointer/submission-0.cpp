/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *dummy = new Node(0), *cp = dummy, *tmp = head, *cp_tmp;
        while (tmp != nullptr) {
            cp->next = new Node(tmp->val);
            mp[tmp] = cp->next;
            cp = cp->next;
            tmp = tmp->next;
        }
        tmp = head;
        cp_tmp = dummy->next;
        while (tmp != nullptr) {
            if (tmp->random != nullptr) {
                cp_tmp->random = mp[tmp->random];
            }
            tmp = tmp->next;
            cp_tmp = cp_tmp->next;
        }
        return dummy->next;
    }
};
