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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        unordered_set<int> val;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if (val.find(k - node->val) != val.end()) {
                return true;
            }
            val.insert(node->val);
            if (node->left) {
                treeQueue.push(node->left);
            }
            if (node->right) {
                treeQueue.push(node->right);
            }
        }
        return false;
    }
};