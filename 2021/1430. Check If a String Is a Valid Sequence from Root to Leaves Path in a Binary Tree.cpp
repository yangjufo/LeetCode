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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return arr.empty();
        }
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        int index = -1;
        while (!treeQueue.empty() && index + 1 < (int)arr.size()) {
            int size = treeQueue.size(); // number of nodes in current level
            index++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                if (node->val != arr[index]) {
                    continue;
                }
                if (node->left == NULL && node->right == NULL) {
                    if (index + 1 == arr.size()) {
                        return true;
                    }
                    continue;
                }
                if (node->left != NULL) {
                    treeQueue.push(node->left);
                }
                if (node->right != NULL) {
                    treeQueue.push(node->right);
                }
            }
        }
        return false;
    }
};