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
    int total = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return total;
    }
    
    void dfs(TreeNode* root, int maxVal) {
        if (root == NULL) return;
        if (root->val >= maxVal) {
            total++;
            maxVal = root->val;
        }
        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }
};