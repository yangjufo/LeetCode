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
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int index = inStart;
        while (index <= inEnd && inorder[index] != preorder[preStart]) {
            index++;
        }
        root->left = buildTree(preorder, inorder, preStart + 1, preStart + index - inStart, inStart, index - 1);
        root->right = buildTree(preorder, inorder, preStart + index - inStart + 1, preEnd, index + 1, inEnd);
        
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
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        stack<TreeNode*> treeStack;
        
        TreeNode *root = NULL, *prev = root;        
        for (int i = 0; i < preorder.size(); i++) {
            TreeNode *node = new TreeNode(preorder[i]);
            if (root == NULL) {
                root = node;                
            } else {
                if (inorderMap[preorder[i]] < inorderMap[treeStack.top()->val]) {
                    treeStack.top()->left = node;
                } else {                    
                    while (!treeStack.empty() && inorderMap[preorder[i]] > inorderMap[treeStack.top()->val]) {
                        prev = treeStack.top();
                        treeStack.pop();
                    }
                    prev->right = node;
                }
            }            
            treeStack.push(node);
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
    unordered_map<int, int> inorderMap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);                                
        int index = inorderMap[preorder[preStart]];                
        
        root->left = buildTree(preorder, inorder, preStart + 1, inStart, index -1);
        root->right = buildTree(preorder, inorder, preStart + index - inStart + 1, index + 1, inEnd);
        
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
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preEnd < preStart) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootInOrder = inStart;
        while (rootInOrder <= inEnd && inorder[rootInOrder] != preorder[preStart]) {
            rootInOrder++;
        }
        root->left = buildTree(preorder, preStart + 1, preStart + rootInOrder - inStart,inorder,  inStart, rootInOrder - 1);
        root->right = buildTree(preorder, preStart + rootInOrder - inStart + 1, preEnd, inorder, rootInOrder + 1, inEnd);
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
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        
        TreeNode* root = new TreeNode(preorder[0]), *prev = root;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        for (int index = 1; index < preorder.size(); index++) {
            TreeNode* node = new TreeNode(preorder[index]);
            if (indexMap[node->val] < indexMap[treeStack.top()->val]) {
                prev->left = node;
            } else {
                while (!treeStack.empty() && indexMap[node->val] > indexMap[treeStack.top()->val]) {
                    prev = treeStack.top();
                    treeStack.pop();
                }
                prev->right = node;                
            }
            treeStack.push(node);
            prev = node;
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
    unordered_map<int, int> inIndexes;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inIndexes[inorder[i]] = i;
        }
        return buildTree(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inPos = inIndexes[preorder[preStart]];
        root->left = buildTree(preorder, preStart + 1, preStart + inPos - inStart, inorder, inStart, inPos - 1);
        root->right = buildTree(preorder, preStart + inPos - inStart + 1, preEnd, inorder, inPos + 1, inEnd);
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
        if (preorder.empty()) return NULL;
        unordered_map<int, int> inIndexes;
        for (int i = 0; i < inorder.size(); i++) {
            inIndexes[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]), *prev = root;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            if (inIndexes[preorder[i]] < inIndexes[treeStack.top()->val]) {
                prev->left = node;
            } else {
                while (!treeStack.empty() && inIndexes[preorder[i]] > inIndexes[treeStack.top()->val]) {
                    prev = treeStack.top();
                    treeStack.pop();
                }                
                prev->right = node;
            }
            treeStack.push(node);
            prev = node;
        }
        return root;
    }
};