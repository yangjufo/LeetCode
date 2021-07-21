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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        int sum = 0;
        if (root->left != NULL) {
            sum += (isLeaf(root->left) ? root->left->val : sumOfLeftLeaves(root->left));
        }
        if (root->right != NULL) {
            sum += (isLeaf(root->right) ? 0 : sumOfLeftLeaves(root->right));
        }
        return sum;
    }
    
    bool isLeaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }
};