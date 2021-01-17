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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* prev = NULL;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            root = stack.top();
            stack.pop();            
            if (root->right != NULL) {
                stack.push(root->right);
            }    
            if (root->left != NULL) {
                stack.push(root->left);
            } 
            if (prev != NULL) {
                prev->right = root;                
            }
            prev = root;
            root->left = root->right = NULL;
        }
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
    void flatten(TreeNode* root) {        
        TreeNode* prev = NULL;
        preorder(root, prev);
    }
    
    void preorder(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (prev != NULL) {
            prev->right = root;            
        }
        prev = root;
        root->left = root->right = NULL;
        preorder(left, prev);
        preorder(right, prev);                
    }
};