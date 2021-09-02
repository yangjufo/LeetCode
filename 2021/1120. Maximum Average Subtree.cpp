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
    double res = 0;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return res;        
    }
    
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        auto left = dfs(root->left), right = dfs(root->right);
        res = max(res, (double)(left.first + right.first + root->val) / (left.second + right.second + 1));
        return {left.first + right.first + root->val, left.second + right.second + 1};
    }
};