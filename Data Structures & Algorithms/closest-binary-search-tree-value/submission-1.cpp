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
    int closestValue(TreeNode* root, double target, int last) {
        if (!root) {
            return last;
        }
        if (abs(root->val - target) <= abs(last - target)) {
            last = root->val;
        }
        int left = closestValue(root->right, target, last);
        int right = closestValue(root->left, target, last);
        if (abs(left - target) <= abs(right - target)) {
            return left;
        }
        return right;
    }
public:
    int closestValue(TreeNode* root, double target) {
        return closestValue(root, target, INT_MAX);
    }
};
