/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> treeStack;
        bool pFound = false;
        while (root != NULL || !treeStack.empty()) {
            while (root != NULL) {                
                treeStack.push(root);
                root = root->left;
            }
            root = treeStack.top();
            treeStack.pop();
            if (pFound) return root;
            if (root == p) pFound = true;
            root = root->right;
        }
        return NULL;                
    }      
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pFound = false;
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        TreeNode* left = inorderSuccessor(root->left, p);
        if (left != NULL) return left;
        
        if (pFound) return root;
        if (root == p) pFound = true;
        
        TreeNode* right = inorderSuccessor(root->right, p);        
        return right;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = NULL;
        
        while (root != NULL) {
            if (root->val > p->val) {
                candidate = root;
                root = root->left;                
            } else {
                root = root->right;
            }
        }
        return candidate;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = NULL;
        while (root != NULL) {
            if (root->val <= p->val) {
                root = root->right;
            } else if (root->val > p->val) {
                candidate = root;
                root = root->left;
            }
        }
        return candidate;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> treeStack;        
        bool found = false;
        while (root != NULL || !treeStack.empty()) {
            while (root != NULL) {
                treeStack.push(root);
                root = root->left;
            }
            root = treeStack.top();
            treeStack.pop();
            if (found) {
                return root;
            }
            if (p == root) found = true;
            root = root->right;
        }
        return NULL;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* cand = NULL;
        while (root != NULL) {
            if (root->val <= p->val) {
                root = root->right;
            } else {
                cand = root;
                root = root->left;
            }
        }
        return cand;
    }
};