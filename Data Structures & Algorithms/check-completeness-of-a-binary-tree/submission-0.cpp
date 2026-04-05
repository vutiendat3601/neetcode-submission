/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        while (k = q.size()) {
            while (k--) {
                auto node = q.front();
                q.pop();
                if (!node) {
                    while (q.size()) {
                        node = q.front();
                        q.pop();
                        if (node) {
                            return 0;
                        }
                    }
                    return 1;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return 1;
    }
};