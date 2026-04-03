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
    vector<int> ans;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return ans;
    }

    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
            return;
        }
        if (root->left != nullptr) {
            traversal(root->left);
        }
        ans.push_back(root->val);
        if (root->right != nullptr) {
            traversal(root->right);
        }
    }
};