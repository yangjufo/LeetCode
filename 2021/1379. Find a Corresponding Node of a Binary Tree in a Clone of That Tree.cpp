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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        inorder(original, cloned, target, ans);
        return ans;
    }
    
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& ans) {
        if (original != NULL && ans == NULL) {
            inorder(original->left, cloned->left, target, ans);
            if (original == target) {
                ans = cloned;
                return;
            }
            inorder(original->right, cloned->right, target, ans);
        }
    }
};