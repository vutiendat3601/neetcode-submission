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
    void longestConsecutive(TreeNode* root, int last, int cnt) {
        if (!root) {
            return;
        }
        cnt = root->val - last == 1 ? cnt + 1 : 1;
        ans = max(ans, cnt);
        longestConsecutive(root->left, root->val, cnt);
        longestConsecutive(root->right, root->val, cnt);
    }
public:
    int longestConsecutive(TreeNode* root) {
        longestConsecutive(root, INT_MAX, 0);
        return ans;
    }
};
