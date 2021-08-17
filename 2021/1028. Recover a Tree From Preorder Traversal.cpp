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
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return recover(traversal, index, 0);
    }
    
    TreeNode* recover(string& traversal, int& index, int currLevel) {
        if (index >= traversal.length()) return NULL;
        int level = 0;
        while (traversal[index] == '-') {
            level++;
            index++;
        }        
        if (level < currLevel) {
            index -= level;            
            return NULL;
        }
        int start = index;
        while (index < traversal.length() && traversal[index] != '-') {
            index++;
        }
        TreeNode* root = new TreeNode(stoi(traversal.substr(start, index - start)));
        root->left = recover(traversal, index, level + 1);
        root->right = recover(traversal, index, level + 1);
        return root;
    }
};