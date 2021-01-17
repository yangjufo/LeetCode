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
    void recoverTree(TreeNode* root) {        
        stack<TreeNode*> stack;
        TreeNode *left = NULL, *right = NULL, *prev = NULL;
        while (root != NULL || !stack.empty()) {
            while (root != NULL) {
                stack.push(root);                                    
                root = root->left;                
            }
            root = stack.top();
            stack.pop();
            if (prev != NULL && root->val < prev->val) {                
                left = left == NULL ? prev : left;
                right = root;
            }
            prev = root;
            root = root->right;            
        }
        
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
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
    void recoverTree(TreeNode* root) {        
        TreeNode *left = NULL, *right = NULL, *prev = NULL, *pred = NULL;
        
        while (root != NULL) {
            if (root->left != NULL) {
                pred = root->left;
                while (pred->right != NULL && pred->right != root) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = root;
                    root = root->left;
                }
                else {
                    if (prev != NULL && root->val < prev->val) {
                        right = root;
                        if (left == NULL) left = prev;
                    }
                    prev = root;
                    pred->right = NULL;
                    root = root->right;
                }
            } else {
                if (prev != NULL && root->val < prev->val) {
                    right = root;
                    if (left == NULL) left = prev;
                }
                prev = root;
                root = root->right;
            }
        }
        
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
};