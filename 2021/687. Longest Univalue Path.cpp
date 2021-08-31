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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root);
        return maxLen - 1;
    }
    
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        auto left = dfs(root->left), right = dfs(root->right);
        int currLen = 1, retLen = 1;
        if (left.second > 0 && left.first == root->val) {
            currLen += left.second;
            retLen = max(retLen, 1 + left.second);
        }
        if (right.second > 0 && right.first == root->val) {
            currLen += right.second;
            retLen = max(retLen, 1 + right.second);
        }
        maxLen = max(maxLen, currLen);
        return {root->val, retLen};
    }
};