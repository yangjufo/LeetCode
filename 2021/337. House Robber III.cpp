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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
    
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);        
        return {max(root->val + left.second + right.second, left.first + right.first), left.first + right.first};
    }
};