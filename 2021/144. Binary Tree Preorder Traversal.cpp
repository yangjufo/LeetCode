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
