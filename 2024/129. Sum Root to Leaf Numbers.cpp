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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int num) {
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return num;
        }
        int left = root->left == NULL ? 0 : dfs(root->left, num);
        int right = root->right == NULL ? 0 : dfs(root->right, num);
        return left + right;
    }
};