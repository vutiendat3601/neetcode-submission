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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        bool leftFirst = 1;
        while (k = q.size()) {
            stack<TreeNode*> st;
            vector<int> vals;
            while (k--) {
                auto node = q.front();
                st.push(node);
                q.pop();
            }
            while (st.size()) {
                auto node = st.top();
                st.pop();
                vals.push_back(node->val);
                if (leftFirst) {
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                } else {
                    if (node->right)
                        q.push(node->right);
                    if (node->left)
                        q.push(node->left);
                }
            }
            ans.push_back(vals);
            leftFirst = !leftFirst;
        }

        return ans;
    }
};