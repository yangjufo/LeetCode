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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;        
        if (isSameTree(s, t))
            return true;        
        return isSubtree(s->left, t) || isSubtree(s->right, t);           
    }

private:
    bool isSameTree(TreeNode* s, TreeNode* t){
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;
        if (s->val != t->val)
            return false;
        else
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    
};