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
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        int inc = 1, dec = 1;
        if (root->left) {
            auto [l_inc, l_dec] = dfs(root->left);
            if (root->left->val + 1 == root->val) {
                inc = max(inc, l_inc + 1);
            }
            if (root->left->val - 1 == root->val) {
                dec = max(dec, l_dec + 1);
            }
        }
        if (root->right) {
            auto [r_inc, r_dec] = dfs(root->right);
            if (root->right->val + 1 == root->val) {
                inc = max(inc, r_inc + 1);
            }
            if (root->right->val - 1 == root->val) {
                dec = max(dec, r_dec + 1);
            }
        }
        ans = max(ans, inc + dec - 1);
        return {inc, dec};
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
