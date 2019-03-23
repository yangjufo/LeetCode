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
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;        
        return isValidBST(root, INT_MIN, INT_MAX, false, false);             
    }
    
private:
    bool isValidBST(TreeNode* root, int leftMin, int rightMax, bool leftFlag, bool rightFlag){       
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL)                    
            return root->right->val > root->val && (root->right->val < rightMax || !rightFlag)  && isValidBST(root->right, root->val, rightMax, true, rightFlag);        
        if (root->right == NULL)
            return root->left->val < root->val && (root->left->val > leftMin ||  !leftFlag) && isValidBST(root->left, leftMin, root->val, leftFlag, true);
        return root->right->val > root->val && (root->right->val < rightMax || !rightFlag) && root->left->val < root->val && (root->left->val > leftMin || !leftFlag) && isValidBST(root->left, leftMin, root->val, leftFlag, true) && isValidBST(root->right, root->val, rightMax, true, rightFlag);
    }        
};