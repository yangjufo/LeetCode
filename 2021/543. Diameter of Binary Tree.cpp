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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxPath = 0;
        dfs(root, maxPath);
        return maxPath;        
    }
    
    int dfs(TreeNode* root, int& maxPath) {
        if (root == NULL) return 0;
        int left = dfs(root->left, maxPath);
        int right = dfs(root->right, maxPath);
        maxPath = max(left + right, maxPath);
        return max(left, right) + 1;
    }
};