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
    TreeNode* root;

    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return 0;
        }
        if (attempt(root1, root2)) {
            return 1;
        }
       return dfs(root1->left, root2) ||
        dfs(root1->right, root2);
    }

    bool attempt(TreeNode* root1, TreeNode* root2) {
        if (!root2 || root1 == root2) {
            return 0;
        }
        swap(root1->val, root2->val);
        if (isBST(root)) {
            return 1;
        }
        swap(root1->val, root2->val);
        return attempt(root1, root2->left) || attempt(root1, root2->right);
    }

    bool isBST(TreeNode* node) {
        TreeNode* prev = nullptr;
        return inorder(node, prev);
    }

    bool inorder(TreeNode* node, TreeNode*& prev) {
        if (!node) return true;
        if (!inorder(node->left, prev)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        return inorder(node->right, prev);
    }
public:
    void recoverTree(TreeNode* root) {
        this->root = root;
        dfs(root, root);
    }
};

// Brute Force, try to swap all pair of nodes, time: O(n^2), space: O(n)