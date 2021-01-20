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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;
        dfs(root, "", ans);
        return ans;
    }
    
    void dfs(TreeNode* root, string path, vector<string>& ans) {                
        path += to_string(root->val);
        if (root->left != NULL || root->right != NULL) {
            path += "->";
            if (root->left != NULL) {
                dfs(root->left, path, ans);                
            }
            if (root->right != NULL) {
                dfs(root->right, path, ans);
            }
        } else {
            ans.push_back(path);
        }        
    }
};