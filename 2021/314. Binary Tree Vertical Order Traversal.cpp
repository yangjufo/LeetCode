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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> left, right;
        queue<TreeNode*> treeQueue;
        queue<int> levelQueue;
        treeQueue.push(root);
        levelQueue.push(0);
        while (!treeQueue.empty()) {
            TreeNode* node = treeQueue.front();
            int level = levelQueue.front();
            treeQueue.pop();
            levelQueue.pop();            
            if (level >= 0) {
                if (level >= right.size()) {
                    right.push_back({});
                }
                right[level].push_back(node->val);
            } else {
                if (-level > left.size()) {
                    left.push_back({});
                }
                left[-level - 1].push_back(node->val);
            }
            if (node->left != NULL) {
                treeQueue.push(node->left);
                levelQueue.push(level - 1);
            }
            if (node->right != NULL) {
                treeQueue.push(node->right);
                levelQueue.push(level + 1);
            }
        } 
        vector<vector<int>> res;
        for (int i = (int)left.size() - 1; i >= 0; i--) {
            res.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            res.push_back(right[i]);
        }
        return res;
    }        
};