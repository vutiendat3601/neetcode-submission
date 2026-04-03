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
    int targetSum;
    bool check(TreeNode* root, int sum) {
        if (!root->left && !root->right) {
            return sum + root->val == targetSum;
        }
        int nextVal = sum + root->val;
        return (root->left && check(root->left, nextVal)) ||
               (root->right && check(root->right, nextVal));
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        return root ? check(root, 0) : 0;
    }
};