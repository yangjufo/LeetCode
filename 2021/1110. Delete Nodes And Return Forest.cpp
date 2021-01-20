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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> delSet(to_delete.begin(), to_delete.end());        
        delNodes(root, delSet, forest);
        if (delSet.find(root->val) == delSet.end()) {
            forest.push_back(root);
        }
        return forest;        
    }
    
    TreeNode* delNodes(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& forest) {
        if (root == NULL) return NULL;
        TreeNode* left = delNodes(root->left, to_delete, forest);
        TreeNode* right = delNodes(root->right, to_delete, forest); 
        if (to_delete.find(root->val) != to_delete.end()) {
            if (left != NULL) {
                forest.push_back(left);
            } 
            if (right != NULL) {
                forest.push_back(right);
            }
            return NULL;
        }
        root->left = left;
        root->right = right;
        return root;
    }
};