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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        int left = dfs(root->left, res), right = dfs(root->right, res);
        res = max(res, left + right + root->val);
        return max(0, max(left + root->val, right + root->val));
    }
};