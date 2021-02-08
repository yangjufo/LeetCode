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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
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
    vector<int> preorderTraversal(TreeNode* root) {        
        vector<int> res;        
        stack<TreeNode*> treeStack;
        while (root != NULL || !treeStack.empty()) {
            while (root != NULL) {                
                res.push_back(root->val);
                treeStack.push(root);
                root = root->left;
            }
            root = treeStack.top();
            treeStack.pop();            
            root = root->right;
        }
        return res;
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
    vector<int> preorderTraversal(TreeNode* root) {        
        vector<int> res;        
        stack<TreeNode*> treeStack;
        while (root != NULL || !treeStack.empty()) {
            res.push_back(root->val);
            if (root->right != NULL) treeStack.push(root->right);
            root = root->left;
            if (root == NULL && !treeStack.empty()) {
                root = treeStack.top();
                treeStack.pop();
            }            
        }
        return res;
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
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> nums;
        while (root != NULL) {
            if (root->left != NULL) {
                TreeNode* rootPrev = root->left;
                while (rootPrev->right != NULL && rootPrev->right != root) {
                    rootPrev = rootPrev->right;
                }
                if (rootPrev->right == NULL) {
                    rootPrev->right = root;
                    nums.push_back(root->val);
                    root = root->left;
                } else {
                    rootPrev->right = NULL;                    
                    root = root->right;
                }
            } else {
                nums.push_back(root->val);                                
                root = root->right;
            }
        }
        return nums;
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> nums;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            root = stack.top();
            stack.pop();
            nums.push_back(root->val);
            if (root->right != NULL) {
                stack.push(root->right);
            }
            if (root->left != NULL) {
                stack.push(root->left);
            }
        }
        return nums;
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            root = treeStack.top();
            treeStack.pop();
            res.push_back(root->val);
            if (root->right != NULL) {
                treeStack.push(root->right);                
            }
            if (root->left != NULL) {
                treeStack.push(root->left);
            }
        }
        return res;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root != NULL) {            
            if (root->left != NULL) {
                TreeNode* rightMost = root->left;
                while (rightMost->right != NULL && rightMost->right != root) {
                    rightMost = rightMost->right;
                }
                if (rightMost->right == NULL) {
                    rightMost->right = root;
                    res.push_back(root->val);
                    root = root->left;
                } else {
                    rightMost->right = NULL;
                    root = root->right;
                }
            } else {
                res.push_back(root->val);
                root = root->right;
            }
            
        }
        return res;
    }
};