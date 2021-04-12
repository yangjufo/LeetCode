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
    int deepest = 0, sum = 0;
    int deepestLeavesSum(TreeNode* root) {
        deepestLeaveSum(root, 1);
        return sum;
    }
    
    void deepestLeaveSum(TreeNode* root, int depth) {
        if (root == NULL) return;
        if (depth > deepest) {
            deepest = depth;
            sum = root->val;
        } else if (depth == deepest) {
            sum += root->val;
        }
        deepestLeaveSum(root->left, depth + 1);
        deepestLeaveSum(root->right, depth + 1);
    }
};