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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root, *prev = root;
        while (node != NULL) {
            prev = node;
            if (node->val > val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (prev == NULL) {
            root = new TreeNode(val);
        }
        else if (val > prev->val) {
            prev->right = new TreeNode(val);
        } else {
            prev->left = new TreeNode(val);
        }
        return root;
    }
};

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
        } else if (root->val < val) {
            if (root->right == NULL) {
                root->right = new TreeNode(val);
            } else {
                insertIntoBST(root->right, val);
            }
        } else {
            if (root->left == NULL) {
                root->left = new TreeNode(val);
            } else {
                insertIntoBST(root->left, val);
            }
        }
        return root;
    }
};