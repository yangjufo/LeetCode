/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }

    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }
        if (root->val < minVal || root->val > maxVal) {
            return false;
        }
        return isValid(root->left, minVal, min(maxVal, (long)root->val - 1)) &&
               isValid(root->right, max(minVal, (long)root->val + 1), maxVal);
    }
};