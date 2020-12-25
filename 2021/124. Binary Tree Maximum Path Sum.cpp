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
        int maxSum = root->val;                
        down(root, maxSum);
        return maxSum;
    }
    
    int down(TreeNode* root, int& maxSum) {
        if (root == NULL) return 0;
        int left = max(down(root->left, maxSum), 0);
        int right = max(down(root->right, maxSum), 0); 
        
        maxSum = max(left + right + root->val, maxSum);
        return max(left, right) + root->val;
    }
    
};