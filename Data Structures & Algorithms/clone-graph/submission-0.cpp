/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> mp;
    Node* dfs(Node* node) {
        if (!node)
            return node;
        if (mp.count(node->val))
            return mp[node->val];
        mp[node->val] = new Node(node->val);
        for (auto& nei : node->neighbors)
            mp[node->val]->neighbors.push_back(dfs(nei));
        return mp[node->val];
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
