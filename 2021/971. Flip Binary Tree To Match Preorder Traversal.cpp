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
    vector<int> nodes;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int index = 0;
        if (flipMatchVoyage(root, voyage, index)) {
            return nodes;
        }
        return {-1};
    }
    
    bool flipMatchVoyage(TreeNode* root, vector<int>& voyage, int& index) {     
        if (root == NULL || index >= voyage.size()) return true;
        if (root->val != voyage[index]) return false;
        
        int rightIndex = index + 1;
        index++;
        if (flipMatchVoyage(root->left, voyage, index) && flipMatchVoyage(root->right, voyage, index)) return true;        
        index = rightIndex;
        if (flipMatchVoyage(root->right, voyage, index) && flipMatchVoyage(root->left, voyage, index)) {
            nodes.push_back(root->val);
            return true;
        }
        return false;
    }
};