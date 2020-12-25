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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> rQueue;
        rQueue.push(root);
        while (!rQueue.empty()) {
            TreeNode* rNode = rQueue.front();
            rQueue.pop();
            TreeNode* tmp = rNode->left;
            rNode->left = rNode->right;
            rNode->right = tmp;
            if (rNode->left != NULL) rQueue.push(rNode->left);
            if (rNode->right != NULL) rQueue.push(rNode->right);
        }
        return root;
        
    }
};