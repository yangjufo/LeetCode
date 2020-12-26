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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == NULL || u == NULL) return NULL;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            int size = treeQueue.size();
            TreeNode* last = NULL;
            for (int i = 0; i < size; i++) {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                if (last == u) return node;
                last = node;
                if (node->left != NULL) treeQueue.push(node->left);
                if (node->right != NULL) treeQueue.push(node->right);
            }
        }
        return NULL;        
    }
};