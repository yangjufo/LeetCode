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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        down(root, maxLen);
        return maxLen - 1;
    }

    int down(TreeNode* root, int& maxLen) {
        if (root == NULL) {
            return 0;
        }
        int left = down(root->left, maxLen), right = down(root->right, maxLen);
        maxLen = max(maxLen, left + right + 1);
        return max(left, right) + 1;
    }
};