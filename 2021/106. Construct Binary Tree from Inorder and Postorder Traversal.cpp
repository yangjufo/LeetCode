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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postEnd) {
        if (postEnd < 0 || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int i = inEnd;
        while (i >= inStart && inorder[i] != postorder[postEnd]) {
            i--;
        }
        root->right = buildTree(inorder, i + 1, inEnd, postorder, postEnd - 1);
        root->left = buildTree(inorder, inStart, i - 1, postorder, postEnd - (inEnd - i) - 1);
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        
        stack<TreeNode*> nodeStack;
        TreeNode *root, *node, *prev;
        root = node = prev = NULL;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            node = new TreeNode(postorder[i]);
            if (root == NULL) {
                root = node;
            } else {
                if (inorderIndex[postorder[i]] > inorderIndex[nodeStack.top()->val]) {
                    prev->right = node;
                } else {
                    while (!nodeStack.empty() && inorderIndex[postorder[i]] < inorderIndex[nodeStack.top()->val]) {
                        prev = nodeStack.top();
                        nodeStack.pop();
                    }
                    prev->left = node;
                }                
            }
            nodeStack.push(node);
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart > postEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int rootIndex = inStart;
        while (rootIndex <= inEnd && inorder[rootIndex] != postorder[postEnd]) {
            rootIndex++;
        }
        
        root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + rootIndex - inStart - 1);
        root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + rootIndex - inStart, postEnd - 1);
        
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        
        TreeNode* root = NULL;
        stack<TreeNode*> treeStack;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            TreeNode* node = new TreeNode(postorder[i]);
            if (root == NULL) {
                root = node;
            } else {
                if (inorderMap[postorder[i]] > inorderMap[treeStack.top()->val]) {
                    treeStack.top()->right = node;
                } else {
                    TreeNode* prev = NULL;
                    while (!treeStack.empty() && inorderMap[postorder[i]] < inorderMap[treeStack.top()->val]) {
                        prev = treeStack.top();
                        treeStack.pop();
                    }
                    prev->left = node;
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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postEnd) {
        if (inStart > inEnd) return NULL;        
        
        TreeNode* root = new TreeNode(postorder[postEnd]);    
        int index = inorderMap[postorder[postEnd]];
        
        root->right = buildTree(inorder, postorder, index + 1, inEnd, postEnd - 1);
        root->left = buildTree(inorder, postorder, inStart, index - 1, postEnd - 1 - (inEnd - index));
        
        return root;
    }
    
};