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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {        
        if (root == NULL || root->left == NULL) return root;
        stack<TreeNode*> treeStack;        
        while (root != NULL) {
            treeStack.push(root);            
            treeStack.push(root->right);            
            root->right = NULL;            
            TreeNode* left = root->left;
            root->left = NULL;
            root = left;
        } 
        while (treeStack.top() == NULL) {
            treeStack.pop();
        }
        root = treeStack.top();
        TreeNode* currRoot = treeStack.top();
        treeStack.pop();
        while (!treeStack.empty()) {           
            if (!treeStack.empty()) {
                currRoot->left = treeStack.top();
                treeStack.pop();
            }
            if (!treeStack.empty()) {
                currRoot->right = treeStack.top();  
                treeStack.pop();
                currRoot = currRoot->right;
            }
        }
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {        
        if (root == NULL || (root->left == NULL && root->right == NULL)) return root;
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        
        root->left->left = root->right;
        root->left->right = root;
        
        root->left = root->right = NULL;
        
        return newRoot;
        
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL) return root;
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        root->left->left = root->right;
        root->left->right = root;
        root->left->right->left = root->left->right->right = NULL;        
        return newRoot;
    }
};