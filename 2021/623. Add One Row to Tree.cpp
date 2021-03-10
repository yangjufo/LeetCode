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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return addOneRow(root, v, d, true);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d, bool leftSub) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            if (leftSub) {
                newRoot->left = root;
            } else {
                newRoot->right = root;
            }
            return newRoot;
        }        
        if (root == NULL) return NULL;
        root->left = addOneRow(root->left, v, d - 1, true);
        root->right = addOneRow(root->right, v, d - 1, false);        
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        int depth = 1;
        while (depth < d - 1) {
            int size = treeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                if (node->left != NULL) treeQueue.push(node->left);
                if (node->right != NULL) treeQueue.push(node->right);
            }
            depth++;
        }
        while (!treeQueue.empty()) {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            TreeNode* leftRoot = node->left;
            node->left = new TreeNode(v);
            node->left->left = leftRoot;
            TreeNode* rightRoot = node->right;
            node->right = new TreeNode(v);
            node->right->right = rightRoot;
        }
        return root;
    }
};