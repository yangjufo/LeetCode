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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL) return res;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            int size = treeQueue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                root = treeQueue.front();
                treeQueue.pop();
                sum += root->val;
                if (root->left != NULL) {
                    treeQueue.push(root->left);
                }
                if (root->right != NULL) {
                    treeQueue.push(root->right);
                }
            }
            res.push_back(sum / size);
        }
        return res;
    }
};