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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> treeStack;
        while (root != NULL || !treeStack.empty()) {
            while (root != NULL) {
                res.push_back(root->val);
                treeStack.push(root);
                root = root->right;
            }
            root = treeStack.top();
            treeStack.pop();
            root = root->left;
        }
        reverse(res.begin(), res.end());
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> treeStack;
        while (root != NULL || !treeStack.empty()) {
            while (root != NULL) {
                if (root->right != NULL) {
                    treeStack.push(root->right);
                }
                treeStack.push(root);
                root = root->left;
            }
            
            root = treeStack.top();
            treeStack.pop();
            
            if (!treeStack.empty() && root->right == treeStack.top()) {
                treeStack.pop();
                treeStack.push(root);
                root = root->right;
            } else {
                res.push_back(root->val);
                root = NULL;
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
    vector<int> postorderTraversal(TreeNode* root) {        
        vector<int> res;
        stack<TreeNode*> treeStack;        
        
        while (root != NULL || !treeStack.empty()) {
            while (root != NULL) {
                if (root->right != NULL) {
                    treeStack.push(root->right);
                }
                treeStack.push(root);
                root = root->left;                                
            }
            
            root = treeStack.top();
            treeStack.pop();
            
            if (!treeStack.empty() && root->right == treeStack.top()) {                
                treeStack.pop();
                treeStack.push(root);
                root = root->right;
            } else {
                res.push_back(root->val);
                root = NULL;
            }        
        }        
        return res;
        
    }
};