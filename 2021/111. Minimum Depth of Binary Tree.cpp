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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        int depth = 0;
        while (!treeQueue.empty()) {
            depth++;
            int size = treeQueue.size();
            for (int i = 0; i < size; i++) {
                root = treeQueue.front();
                treeQueue.pop();
                if (root->left == NULL && root->right == NULL) return depth;
                if (root->left != NULL) {
                    treeQueue.push(root->left);
                }
                if (root->right != NULL) {
                    treeQueue.push(root->right);
                }
            }
        }
        return 0;
    }
};