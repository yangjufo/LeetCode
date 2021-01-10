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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        res.push_back(root->val);
        leftBoundary(root->left, res);
        leaves(root->left, res);
        leaves(root->right, res);
        rightBoundary(root->right, res);
        return res;    
    }
    
    void leftBoundary(TreeNode* root, vector<int>& res) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        res.push_back(root->val);
        if (root->left != NULL) leftBoundary(root->left, res);
        else leftBoundary(root->right, res);
    }
    
    void rightBoundary(TreeNode* root, vector<int>& res) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        if (root->right != NULL) rightBoundary(root->right, res);
        else rightBoundary(root->left, res);
        res.push_back(root->val);
    }
    
    void leaves(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->val);
            return;
        }
        leaves(root->left, res);
        leaves(root->right, res);        
    }
};