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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        queue.push(root);
        bool leftToRight = true;
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> curr;
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                curr.push_back(node->val);
                if (node->left != NULL) {
                    queue.push(node->left);
                }
                if (node->right != NULL) {
                    queue.push(node->right);
                }
            }
            if (!leftToRight) {
                reverse(curr.begin(), curr.end());
            }
            res.push_back(curr);
            leftToRight = !leftToRight;
        }
        return res;
    }
};