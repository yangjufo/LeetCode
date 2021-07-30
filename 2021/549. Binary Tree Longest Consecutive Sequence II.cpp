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
        if (root == NULL) return NULL;
        dfs(root, -1);
        return maxLen;
    }
    
    pair<int, int> dfs(TreeNode* root, int parent) {        
        if (root == NULL) {
            return {0, 0};
        }        
        auto leftLens = dfs(root->left, root->val);            
        auto rightLens = dfs(root->right, root->val);
        maxLen = max(maxLen, max(leftLens.first + rightLens.second + 1, leftLens.second + rightLens.first + 1));
        if (root->val == parent - 1) {
            return {1 + max(leftLens.first, rightLens.first), 0};
        }
        if (root->val == parent + 1) {
            return {0, 1 + max(leftLens.second, rightLens.second)};
        }
        return {0, 0};
    }
};