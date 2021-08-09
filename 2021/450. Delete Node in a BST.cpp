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
    TreeNode* deleteNode(TreeNode* root, int key) {                
        TreeNode* node = root, *parent = NULL;
        while (node != NULL && node->val != key) {
            parent = node;
            if (node->val > key) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (node == NULL) return root;
        
        TreeNode* del = node;        
        if (node->right != NULL) {                                
            node = node->right;
            TreeNode* prev = NULL;
            while (node != NULL && node->left != NULL) {
                prev = node;
                node = node->left;
            }                
            if (prev != NULL) {
                prev->left = node->right;
                node->right = del->right;
            }
            
            node->left = del->left;
        } else {
            node = node->left;
        }
        if (parent != NULL) {
            if (parent->left == del) {
                parent->left = node;            
            } else {
                parent->right = node;
            }
        } else {
            root = node;
        }
        
        delete del;
        return root;
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
    TreeNode* deleteNode(TreeNode* root, int key) {                
        TreeNode* node = root, *parent = NULL;
        while (node != NULL && node->val != key) {
            parent = node;
            if (node->val > key) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (node == NULL) return root;
        
        TreeNode* del = node;
        if (node->left == NULL && node->right == NULL) {
            node = NULL;
        } else if (node->left == NULL) {
            node = node->right;
        } else if (node->right == NULL) {
            node = node->left;
        } else {                    
            node = node->right;
            TreeNode* prev = NULL;
            while (node != NULL && node->left != NULL) {
                prev = node;
                node = node->left;
            }                
            if (prev != NULL) {
                prev->left = node->right;
                node->right = del->right;
            }            
            node->left = del->left;
        } 
        
        if (parent != NULL) {
            if (parent->left == del) {
                parent->left = node;            
            } else {
                parent->right = node;
            }
        } else {
            root = node;
        }
        
        delete del;
        return root;
    }
};