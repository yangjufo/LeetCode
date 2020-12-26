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
    bool isBalanced(TreeNode* root) {        
        bool balanced = true;
        height(root, balanced);
        return balanced;
    } 
    
    int height (TreeNode* root, bool& balanced) {
        if (root == NULL) return 0;
        int left = height(root->left, balanced);
        int right = height(root->right, balanced);
        if (left - right > 1 || right - left > 1) {
            balanced = false;
        }
        return max(left, right) + 1;
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
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> treeStack;
        unordered_map<TreeNode*, int> nodeHeightMap;
        nodeHeightMap[NULL] = 0;
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
                int left = nodeHeightMap[root->left];
                int right = nodeHeightMap[root->right];
                if (abs(left - right) > 1) return false;
                nodeHeightMap[root] = max(left, right) + 1;
                root = NULL;
            }            
        }
        return true;
    }
};