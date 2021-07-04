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
    int maxLen = 0;
    int longestConsecutive(TreeNode* root) {
        longest(root, INT_MIN, 0);
        return maxLen;
    }
    
    void longest(TreeNode* root, int parent, int len) { 
        maxLen = max(len, maxLen);
        if (root == NULL) return;        
        if (root->val != parent + 1) len = 1;
        else len += 1;
        longest(root->left, root->val, len);
        longest(root->right, root->val, len);
    }
};