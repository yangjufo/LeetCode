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
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }

    void dfs(TreeNode* root, int prev, int& sum) {
        prev = prev * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += prev;
        }
        if (root->left != NULL) {
            dfs(root->left, prev, sum);
        }
        if (root->right != NULL) {
            dfs(root->right, prev, sum);
        }
    }
};