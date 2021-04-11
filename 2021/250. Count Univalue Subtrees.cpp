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
    int count = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        getValSubtrees(root);
        return count;
    }
    
    int getValSubtrees(TreeNode* root) {                
        int left = root->left == NULL ? root->val : getValSubtrees(root->left);        
        int right = root->right == NULL ? root->val : getValSubtrees(root->right);        
        if (left == root->val && right == root->val) {
            count += 1;
            return root->val;
        }
        return 1001;
    }
};