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
    int sum;
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode* root, int tmp) {        
        tmp = (tmp * 2 + root->val) % (int)(pow(10, 9) + 7);
        if (root->left != NULL)
            dfs(root->left, tmp);
        if (root->right != NULL)
            dfs(root->right, tmp);
        if (root->left == NULL && root->right == NULL)
            sum = (sum + tmp) % (int)(pow(10, 9) + 7);
    }
};