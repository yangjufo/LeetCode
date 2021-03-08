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
    int totalSum = 0;
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        sumNumbers(root, 0);
        return totalSum;
    }
    
    void sumNumbers(TreeNode* root, int prev) {
        prev = prev * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            totalSum += prev;
            return;
        }
        if (root->left != NULL) n{
            sumNumbers(root->left, prev);
        }
        if (root->right != NULL) {
            sumNumbers(root->right, prev);
        }
    }
};