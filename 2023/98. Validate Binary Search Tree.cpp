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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, false, INT_MAX, false);
    }

    bool isValidBST(TreeNode* root, int minValue, bool minSeen, int maxValue, int maxSeen) {
        if (root == NULL) {
            return true;
        }
        if (root->val == INT_MIN) {
            if (minValue != INT_MIN || minSeen) {
                return false;
            }
            minSeen = true;
        } else if (root->val == INT_MAX) {
            if (maxValue != INT_MAX || maxSeen) {
                return false;
            }
            maxSeen = true;
        } else if (root->val >= maxValue || root->val <= minValue) {
            return false;
        }
        return isValidBST(root->left, minValue, minSeen, root->val, maxSeen) && isValidBST(root->right, root->val, minSeen, maxValue, maxSeen);
    }
};