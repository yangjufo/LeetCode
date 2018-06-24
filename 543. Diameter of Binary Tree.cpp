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
    int maxLen = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;        
        return max(inDiameterOfBinaryTree(root), maxLen);
    }
private:
    int inDiameterOfBinaryTree(TreeNode* root){                
        if (root->left == NULL && root->right == NULL){
            return 0;
        }
        if (root->left != NULL && root->right != NULL){
            int leftMax = inDiameterOfBinaryTree(root->left) + 1;
            int rightMax = inDiameterOfBinaryTree(root->right) + 1;
            if (leftMax + rightMax > maxLen){
                maxLen = leftMax + rightMax;
            }
            return max(leftMax, rightMax);            
        }
        if (root->left != NULL){
            return inDiameterOfBinaryTree(root->left) + 1;
        }
        if (root->right != NULL){
            return inDiameterOfBinaryTree(root->right) + 1;
        }
    }
};