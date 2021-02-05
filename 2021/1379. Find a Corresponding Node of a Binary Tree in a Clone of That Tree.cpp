/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        inorder(original, cloned, target, ans);
        return ans;
    }
    
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& ans) {
        if (original != NULL && ans == NULL) {
            inorder(original->left, cloned->left, target, ans);
            if (original == target) {
                ans = cloned;
                return;
            }
            inorder(original->right, cloned->right, target, ans);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) return NULL;
        if (original == target) return cloned;
        TreeNode* left = original->left == NULL ? NULL : getTargetCopy(original->left, cloned->left, target);
        if (left != NULL) return left;
        return original->right == NULL ? NULL : getTargetCopy(original->right, cloned->right, target);
    }
};