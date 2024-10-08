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
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> left, right;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 0});
        while (!queue.empty()) {
            TreeNode* node = queue.front().first;
            int level = queue.front().second;
            queue.pop();
            if (level >= 0) {
                if (level >= right.size()) {
                    right.push_back({});
                }
                right[level].push_back(node->val);
            } else {
                if (abs(level) > left.size()) {
                    left.push_back({});
                }
                left[abs(level) - 1].push_back(node->val);
            }
            if (node->left != NULL) {
                queue.push({node->left, level - 1});
            }
            if (node->right != NULL) {
                queue.push({node->right, level + 1});
            }
        }
        vector<vector<int>> res;
        for (int i = left.size() - 1; i >= 0; i--) {
            res.push_back(left[i]);
        }
        for (vector<int>& r : right) {
            res.push_back(r);
        }
        return res;
    }
};