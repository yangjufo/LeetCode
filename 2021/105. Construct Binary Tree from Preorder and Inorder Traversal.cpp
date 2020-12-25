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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {        
        if (preorder.empty() || inorder.empty()) return NULL;
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootInOrder = inStart;
        while (rootInOrder <= inEnd && inorder[rootInOrder] != preorder[preStart]) {
            rootInOrder++;
        }
        if (rootInOrder != inStart) {
            root->left = buildTree(preorder, inorder, preStart + 1, inStart, rootInOrder - 1);                        
        }        
        if (rootInOrder != inEnd) {
            root->right = buildTree(preorder, inorder, preStart + rootInOrder - inStart + 1, rootInOrder + 1, inEnd);
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {                
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;        
        }
        stack<TreeNode*> treeStack;
        TreeNode *root = NULL, *node = NULL, *prev = NULL;        
        for (int index = 0; index < preorder.size(); index++) {  
            node = new TreeNode(preorder[index]);
            if (root == NULL) {
                root = node;                                
                treeStack.push(node);
            } else {
                if (inorderIndexMap[preorder[index]] < inorderIndexMap[treeStack.top()->val]) {
                    prev->left = node;                       
                } else {
                    while (!treeStack.empty() && inorderIndexMap[preorder[index]] > inorderIndexMap[treeStack.top()->val]) {
                        prev = treeStack.top();
                        treeStack.pop();
                    }
                    prev->right = node;
                }
                treeStack.push(node);
            }
            prev = node;
            
        }
        return root;
        
    }
};