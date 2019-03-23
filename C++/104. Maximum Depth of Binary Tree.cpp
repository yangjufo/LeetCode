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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        TreeNode* p = root;        
        int count = 1;
        int left = 0;
        int right = 0;
        if (p->left != NULL){
            left = maxDepth(p->left);
        }
        if (p->right != NULL){
            right = maxDepth(p->right);
        }
        count += max(left, right);
        return count;
    }
};