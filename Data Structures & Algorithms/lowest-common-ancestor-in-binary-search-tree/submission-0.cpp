/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* lowestCommonAncestor(TreeNode* root, const int& p, const int& q) {
        if (q < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pNode,
                                   TreeNode* qNode) {
        int p = pNode->val, q = qNode->val;
        return p < q ? lowestCommonAncestor(root, p, q)
                     : lowestCommonAncestor(root, q, p);
    }
};