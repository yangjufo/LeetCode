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
    int distributeCoins(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
    
    int dfs(TreeNode* root, int& count) {
        if (root == NULL) return 0;
        int left = dfs(root->left, count);
        int right = dfs(root->right, count);
        count += abs(left) + abs(right);
        return root->val + left + right - 1;        
    }
};

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
    int diff = 0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return diff;
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        diff += abs(root->val - left - right - 1);
        return 1 - (root->val - left - right);
    }
};