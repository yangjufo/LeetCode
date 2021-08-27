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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root) - 1, m = height + 1, n = (int)pow(2, height + 1) - 1;
        vector<vector<string>> res(m, vector<string>(n));
        queue<pair<TreeNode*, int>> treeQueue;
        treeQueue.push({root, (n - 1) / 2});
        int row = -1;
        while (!treeQueue.empty()) {            
            row++;
            int size = treeQueue.size();
            for (int i = 0; i < size; i++) {
                 TreeNode* node = treeQueue.front().first;
                int col = treeQueue.front().second;
                treeQueue.pop();         
                res[row][col] = to_string(node->val);
                if (node->left != NULL) {
                    treeQueue.push({node->left, col - (int)pow(2, height - row - 1)});
                }
                if (node->right != NULL) {
                    treeQueue.push({node->right, col + (int)pow(2, height - row - 1)});
                }
            }           
        }
        return res;        
    }
    
    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};