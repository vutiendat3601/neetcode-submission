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
private:
    TreeNode* subRoot;

    bool check(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return 1;
        }
        if (!root1 || !root2 || root1->val != root2->val) {
            return 0;
        }
        return check(root1->left, root2->left) && check(root1->right, root2->right);
    }

    bool traversal(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (root->val == subRoot->val) {
            if (check(root, subRoot)) {
                return 1;
            }
        }
        return traversal(root->left) || traversal(root->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        this->subRoot = subRoot;
        return traversal(root);
    }
};
