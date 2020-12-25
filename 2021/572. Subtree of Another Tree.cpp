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
    bool isSubtree(TreeNode* s, TreeNode* t) {        
        return helper(s, t, t);
    }
    
    bool helper(TreeNode* s, TreeNode* t, TreeNode* tRoot) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val == t->val && helper(s->left, t->left, tRoot) && helper(s->right, t->right, tRoot)) {
            return true;
        }             
        if (t == tRoot) {
            return helper(s->left, t, tRoot) || helper(s->right, t, tRoot);
        }
        return false;
    }
};