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
    int minDiff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        int prev = -100000;
        inorder(root, prev);
        return minDiff;
    }
    
    void inorder(TreeNode* root, int& prev) {
        if (root == NULL) return;        
        inorder(root->left, prev);
        minDiff = min(minDiff, root->val - prev);        
        prev = root->val;
        inorder(root->right, prev);
    }
};