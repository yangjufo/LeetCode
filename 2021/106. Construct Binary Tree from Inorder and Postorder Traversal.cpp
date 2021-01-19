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