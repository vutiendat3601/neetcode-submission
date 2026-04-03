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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        vector<pair<int, int>> tmp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int pos_mx = INT_MIN, pos_mn = INT_MAX, k = 0;
        while (k = q.size()) {
            while (k--) {
                auto& [node, pos] = q.front();
                q.pop();
                tmp.push_back({node->val, pos});
                pos_mn = min(pos_mn, pos), pos_mx = max(pos_mx, pos);
                if (node->left) {
                    q.push({node->left, pos - 1});
                }
                if (node->right) {
                    q.push({node->right, pos + 1});
                }
            }
        }
        int n = pos_mx - pos_mn + 1, offset = abs(pos_mn);
        ans.assign(n, vector<int>());
        for (auto & [val, pos] : tmp) {
            ans[pos + offset].push_back(val);
        }
        return ans;
    }
};