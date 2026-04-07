/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, unordered_set<int>> pref;
    TreeNode* insertNode(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (pref[root->val].count(val)) {
            root->left = insertNode(root->left, val);
        } else {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                pref[inorder[i]].insert(inorder[j]);
            }
        }
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < n; i++) {
            insertNode(root, preorder[i]);
        }
        return root;
    }
};