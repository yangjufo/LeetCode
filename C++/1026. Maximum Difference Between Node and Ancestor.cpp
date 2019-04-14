/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res;    
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        if (root == NULL)
            return res;
        dfs(root, root->val, root->val);
        return res;
    }
    
    void dfs(TreeNode* root, int maxValue, int minValue) {
        maxValue = max(maxValue, root->val);
        minValue = min(minValue, root->val);
        res = max(res, abs(maxValue - minValue));
        if (root->left != NULL) dfs(root->left, maxValue, minValue);
        if (root->right != NULL) dfs(root->right, maxValue, minValue);
    }
};