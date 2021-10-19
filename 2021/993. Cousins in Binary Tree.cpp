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
    bool isCousins(TreeNode* root, int x, int y) {
        auto xInfo = dfs(root, x, -1, 0), yInfo = dfs(root, y, -1, 0);
        return xInfo.first != yInfo.first && xInfo.second == yInfo.second;
    }
    
    pair<int, int> dfs(TreeNode* root, int target, int parent, int depth) {
        if (root == NULL) return {-1, -1};
        if (root->val == target) return {parent, depth};
        auto left = dfs(root->left, target, root->val, depth + 1);
        if (left.second != -1) return left;
        return dfs(root->right, target, root->val, depth + 1);        
    }
};