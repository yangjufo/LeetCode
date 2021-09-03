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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
    
    bool inorder(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) return true;        
        if (!inorder(root->left, prev)) return false;     
        if (prev != NULL && prev->val >= root->val) return false;              
        prev = root;
        return inorder(root->right, prev);
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
    bool isValidBST(TreeNode* root) {
        return dfs(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
    
    bool dfs(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return dfs(root->left, minVal, root->val) && dfs(root->right, root->val, maxVal);
    }
};