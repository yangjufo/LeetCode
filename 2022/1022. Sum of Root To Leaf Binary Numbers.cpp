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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int num) {
        if (root->left == NULL && root->right == NULL) {
            sum += (num << 1) + root->val;
            return;
        }
        if (root->left != NULL) {
            dfs(root->left, (num << 1) + root->val);
        }
        if (root->right != NULL) {
            dfs(root->right, (num << 1) + root->val);
        }
    }
};