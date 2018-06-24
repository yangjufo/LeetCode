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
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root != NULL)            
            findPaths("", root);
        return res;
    }

private:
    void findPaths(string path, TreeNode* root){
        if (root->left == NULL && root->right == NULL){
            res.push_back(path + to_string(root->val));
        }
        if (root->left != NULL){
            findPaths(path + to_string(root->val) + "->", root->left);
        }
        if (root->right != NULL){
            findPaths(path + to_string(root->val) + "->", root->right);
        }                
    }
    
};