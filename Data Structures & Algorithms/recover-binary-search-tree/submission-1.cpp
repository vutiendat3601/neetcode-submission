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
    bool dfs(TreeNode* root, TreeNode* mn, TreeNode* mx) {
        if (!root) {
            return 0;
        }
        if (mn && root->val < mn->val) {
            int tmp = root->val;
            root->val = mn->val;
            mn->val = tmp;
            return 1;
        }
        if (mx && root->val > mx->val) {
            int tmp = root->val;
            root->val = mx->val;
            mx->val = tmp;
            return 1;
        }
        return dfs(root->left, mn, root) || dfs(root->right, root, mx);
    }
public:
    void recoverTree(TreeNode* root) {
        bool ans = dfs(root, nullptr, nullptr);
        while (ans) {
            ans = dfs(root, nullptr, nullptr);
        }
    }
};