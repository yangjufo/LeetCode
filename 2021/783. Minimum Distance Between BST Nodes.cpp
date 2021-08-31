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
    int minDiff = INT_MAX, prev = -1e5 - 1;
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
    
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        minDiff = min(minDiff, root->val - prev);
        prev = root->val;
        inorder(root->right);
    }
};