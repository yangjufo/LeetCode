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
    string res;
    string tree2str(TreeNode* root) {
        dfs(root);
        return res.substr(1, res.length() - 2);
    }
    
    void dfs(TreeNode* root) {        
        res += "(";
        if (root != NULL) {
            res += to_string(root->val);
            if (root->left != NULL || root->right != NULL) {
                dfs(root->left);                
            }            
            if (root->right != NULL) {
                dfs(root->right);
            }
        }        
        res += ")";
    }
};