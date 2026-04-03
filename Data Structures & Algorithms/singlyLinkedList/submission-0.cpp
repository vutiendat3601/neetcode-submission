class LinkedList {
private:
    class Node {
        public:
            int val;
            Node *next;

        public:
            Node(int val): val(val), next(nullptr){}
            Node(int val, Node*next): val(val), next(next){}
    };

    Node *head = nullptr;
public:
    LinkedList() {
    }

    int get(int index) {
        int i = 0;
        Node *node = head;
        while (node && i < index) {
            node = node->next;
            i++;
        }
        return node ? node->val : -1;
    }

    void insertHead(int val) {
        Node *newHead = new Node(val, head);
        head = newHead;
    }
    
    void insertTail(int val) {
        Node *node = head;
        if (node) {
            while (node->next) {
                node = node->next;
            }
            node->next = new Node(val);
        } else {
            insertHead(val);
        }
    }

    bool remove(int index) {
        Node *last = nullptr, *node = head;
        int i = 0;
        while (node && i < index) {
            last = node;
            node = node->next;
           i++;
        }
        if (!node) {
            return 0;
        }
        if (!last) {
            Node *next = head->next;
            head->next = nullptr;
            delete head;
            head = next;
        } else {
            last->next = node->next;
        }
        return 1;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node *node = head;
        while (node) {
            ans.push_back(node->val);
            node = node->next;
        }
        return ans;
    }
};
