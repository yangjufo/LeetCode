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
    long long res = 0, total = 0, mod = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        total = calSum(root);
        dfs(root);
        return res % mod;
    }
    
    int calSum(TreeNode* root) {
        if (root == NULL) return 0;
        return (root->val + calSum(root->left) + calSum(root->right));
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        long long left = dfs(root->left), right = dfs(root->right);
        res = max(res, max(left * (total - left), right * (total - right)));
        return root->val + left + right;
    }
    
};