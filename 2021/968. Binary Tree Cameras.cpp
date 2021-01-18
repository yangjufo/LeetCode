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
    int minCameraCover(TreeNode* root) {
        int count = 0;
        return (dfs(root, count) < 1 ? 1 : 0) + count;
    }
    
    int dfs(TreeNode* root, int& count) {
        if (root == NULL) return 2;
        int left = dfs(root->left, count);
        int right = dfs(root->right, count);
        
        if (left == 0 || right == 0) {
            count++;
            return 1;
        }
        
        return (left == 1 || right == 1) ? 2 : 0;        
    }
};