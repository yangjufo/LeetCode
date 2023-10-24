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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        down(root, res, 0);
        return res;
    }

    void down(TreeNode* root, vector<int>& res, int level) {
        if (root == NULL) return;
        if (level >= res.size()) {
            res.push_back(root->val);
        } else if (root->val > res[level]) {
            res[level] = root->val;
        }
        down(root->left, res, level + 1);
        down(root->right, res, level + 1);
    }
};